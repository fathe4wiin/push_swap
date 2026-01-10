#include "push_swap.h"

static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	sort_three(t_stack **stack_a)
{
	int		highest;

	highest = find_highest_index(*stack_a);
	if ((*stack_a)->index == highest)
		ra(stack_a);
	else if ((*stack_a)->next->index == highest)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

static int	find_min_index_pos(t_stack *stack)
{
	int		min;
	int		pos;
	int		i;

	min = 2147483647;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		pos = find_min_index_pos(*stack_a);
		if (pos <= size / 2)
			while (pos-- > 0)
				ra(stack_a);
		else
			while (pos++ < size)
				rra(stack_a);
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
