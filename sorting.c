#include "push_swap.h"

int assign_n(int size)
{
    if (size <= 50)
        return 5;
    else if (size <= 150)
        return 8;
    else
        return 18;
}

void phase_one(t_stack **stack_a, t_stack **stack_b, t_vars *vars)
{
    int pushed_above;
    int pushed_below;

    pushed_above = 0;
    pushed_below = 0;
    while (stack_size(*stack_a) > 3
        && !(is_sorted(*stack_a) && find_min_index(*stack_a) >= vars->size - 3))
    {
        if ((*stack_a)->index >= vars->size - 3)
            ra(stack_a, 1);
        else if ((*stack_a)->index >= vars->start && (*stack_a)->index <= vars->end)
        {
            pb(stack_a, stack_b, 1);
            if ((*stack_b)->index <= vars->middle)
            {
                rb(stack_b, 1);
                pushed_below++;
            }
            else
                pushed_above++;
            if (pushed_below >= vars->offset)
            {
                vars->start -= vars->offset;
                if (vars->start < 0)
                    vars->start = 0;
                pushed_below = 0;
            }
            if (pushed_above >= vars->offset)
            {
                vars->end += vars->offset;
                if (vars->end >= vars->size)
                    vars->end = vars->size - 1;
                pushed_above = 0;
            }
        }
        else
            ra(stack_a, 1);
    }
}

void phase_two(t_stack **stack_a, t_stack **stack_b, t_vars *vars)
{
    int max_index;
    int target_pos;

    while (*stack_b || vars->down > 0)
    {
        max_index = find_max_index(*stack_b);
        if (vars->down > 0 && stack_last(*stack_a)->index == (*stack_a)->index - 1)
        {
            rra(stack_a, 1);
            vars->down--;
        }
        else if (*stack_b && (*stack_b)->index == max_index)
        {
            pa(stack_a, stack_b, 1);
            if (vars->down > 0 && stack_last(*stack_a)->index == (*stack_a)->index - 1)
            {
                rra(stack_a, 1);
                vars->down--;
            }
        }
        else if (*stack_b && (*stack_b)->index == max_index - 1)
        {
            pa(stack_a, stack_b, 1);
            ra(stack_a, 1);
            vars->down++;
        }
        else if (*stack_b)
        {
            target_pos = find_index_pos(*stack_b, max_index);
            if (target_pos <= stack_size(*stack_b) / 2)
                rb(stack_b, 1);
            else
                rrb(stack_b, 1);
        }
    }
}

t_stack *sort(t_stack **stack_a)
{
    t_vars *vars;
    t_stack *stack_b;

    stack_b = NULL;
    vars = malloc(sizeof(t_vars));
    if (!vars)
        return (NULL);
    vars->size = stack_size((*stack_a));
    vars->n = assign_n(vars->size);
    vars->middle = vars->size / 2;
    vars->offset = vars->size / vars->n;
    vars->start = vars->middle - vars->offset;
    vars->end = vars->middle + vars->offset;
    vars->down = 0;

    if (vars->size <= 5)
        sort_small(stack_a, &stack_b);
    else
    {
        phase_one(stack_a, &stack_b, vars);
        sort_three(stack_a);
        phase_two(stack_a, &stack_b, vars);
    }
    
    return (*stack_a);
}
