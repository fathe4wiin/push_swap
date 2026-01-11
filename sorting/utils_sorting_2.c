/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:19:22 by bfathi            #+#    #+#             */
/*   Updated: 2026/01/12 00:53:45 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_next_target(int max_index, t_stack **stack_b, int *target_pos)
{
	*target_pos = find_index_pos(*stack_b, max_index);
	if (*target_pos <= stack_size(*stack_b) / 2)
		rb(stack_b, 1);
	else
		rrb(stack_b, 1);
}

void	we_have_the_max(t_stack **stack_a, t_stack **stack_b, t_vars *vars)
{
	pa(stack_a, stack_b, 1);
	if (vars->down > 0 && stack_last(*stack_a)->index == (*stack_a)->index - 1)
	{
		rra(stack_a, 1);
		vars->down--;
	}
}
