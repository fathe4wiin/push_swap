/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:19:19 by bfathi            #+#    #+#             */
/*   Updated: 2026/01/12 00:53:42 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max_index(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	max = -1;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	find_index_pos(t_stack *stack, int index)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_min_index(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	min = 2147483647;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

void	expanding_the_chunk(t_vars *vars)
{
	if (vars->pushed_below >= vars->offset)
	{
		vars->start -= vars->offset;
		if (vars->start < 0)
			vars->start = 0;
		vars->pushed_below = 0;
	}
	if (vars->pushed_above >= vars->offset)
	{
		vars->end += vars->offset;
		if (vars->end >= vars->size)
			vars->end = vars->size - 1;
		vars->pushed_above = 0;
	}
}
