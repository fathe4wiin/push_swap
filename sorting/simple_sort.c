/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:19:15 by bfathi            #+#    #+#             */
/*   Updated: 2026/01/12 00:53:35 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_highest_index(t_stack *stack)
{
	int	index;

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
	int	highest;

	highest = find_highest_index(*stack_a);
	if ((*stack_a)->index == highest)
		ra(stack_a, 1);
	else if ((*stack_a)->next->index == highest)
		rra(stack_a, 1);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, 1);
}

static int	find_min_index_pos(t_stack *stack)
{
	int	min;
	int	pos;
	int	i;

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
				ra(stack_a, 1);
		else
			while (pos++ < size)
				rra(stack_a, 1);
		pb(stack_a, stack_b, 1);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
