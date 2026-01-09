#include "push_swap.h"

int assign_n(int size)
{
    if (size <= 10)
        return 5;
    else if (size <= 150)
        return 8;
    else
        return 18;
}

void phase_one(t_stack **stack_a, t_stack **stack_b, t_vars *vars)
{
    while (*stack_a)
    {
        if ((*stack_a)->index >= vars->start && (*stack_a)->index <= vars->end)
        {
            pb(stack_a, stack_b);
            if ((*stack_b)->index < vars->middle)
                rb(stack_b);
            if (stack_size(*stack_b) > (vars->end - vars->start))
            {
                vars->start -= vars->offset;
                vars->end += vars->offset;
                if (vars->start < 0)
                    vars->start = 0;
                if (vars->end >= vars->size)
                    vars->end = vars->size - 1;
            }
        }
        else
            ra(stack_a);
    }
}

void phase_two(t_stack **stack_a, t_stack **stack_b, t_vars *vars)
{
    int max_index;
    int target_pos;

    while (*stack_b || vars->down > 0)
    {
        max_index = find_max_index(*stack_b);
        if (vars->down > 0 && 
            stack_last(*stack_a)->index == (*stack_a)->index + 1)
        {
             rra(stack_a);
             vars->down--;
        }
        else if (*stack_b && (*stack_b)->index == max_index)
        {
            pa(stack_a, stack_b);
            if (vars->down > 0 && 
                stack_last(*stack_a)->index == (*stack_a)->index + 1)
            {
               rra(stack_a);
               vars->down--;
            }
        }
        else if (*stack_b && (*stack_b)->index == max_index - 1)
        {
            pa(stack_a, stack_b);
            ra(stack_a);
            vars->down++;
        }
        else if (*stack_b) 
        {
            target_pos = find_index_pos(*stack_b, max_index);
            if (target_pos <= stack_size(*stack_b) / 2)
                rb(stack_b);
            else
                rrb(stack_b);
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

    phase_one(stack_a, &stack_b, vars);
    
    phase_two(stack_a, &stack_b, vars);
    
    return (*stack_a);
}
