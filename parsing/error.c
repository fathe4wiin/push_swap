/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathe4wiin <fathe4wiin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:18:37 by bfathi            #+#    #+#             */
/*   Updated: 2026/01/14 20:00:12 by fathe4wiin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(t_stack **stack_a, char **split_args)
{
	if (stack_a && *stack_a)
		stack_clear(stack_a);
	if (split_args)
		free_split(split_args);
	if (write(2, "Error\n", 6) == -1)
		(void)0;
	ft_put_move(NULL);
	exit(1);
}
