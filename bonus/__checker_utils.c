/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __checker_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:18:32 by bfathi            #+#    #+#             */
/*   Updated: 2026/01/12 00:52:47 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_instruct(char *instruct)
{
	if (!ft_strcmp(instruct, "sa\n") || !ft_strcmp(instruct, "sb\n")
		|| !ft_strcmp(instruct, "ss\n") || !ft_strcmp(instruct, "pa\n")
		|| !ft_strcmp(instruct, "pb\n") || !ft_strcmp(instruct, "ra\n")
		|| !ft_strcmp(instruct, "rb\n") || !ft_strcmp(instruct, "rr\n")
		|| !ft_strcmp(instruct, "rra\n") || !ft_strcmp(instruct, "rrb\n")
		|| !ft_strcmp(instruct, "rrr\n"))
		return (1);
	return (0);
}

int	get_instruct(char *instruct, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(instruct, "sa\n"))
		sa(stack_a, 0);
	else if (!ft_strcmp(instruct, "sb\n"))
		sb(stack_b, 0);
	else if (!ft_strcmp(instruct, "ss\n"))
		ss(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruct, "pa\n"))
		pa(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruct, "pb\n"))
		pb(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruct, "ra\n"))
		ra(stack_a, 0);
	else if (!ft_strcmp(instruct, "rb\n"))
		rb(stack_b, 0);
	else if (!ft_strcmp(instruct, "rr\n"))
		rr(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruct, "rra\n"))
		rra(stack_a, 0);
	else if (!ft_strcmp(instruct, "rrb\n"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(instruct, "rrr\n"))
		rrr(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}
