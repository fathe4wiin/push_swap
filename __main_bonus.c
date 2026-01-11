/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __bonus_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:18:23 by bfathi            #+#    #+#             */
/*   Updated: 2026/01/12 00:32:42 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

static void	instructions_loop(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!is_instruct(line))
	{
		free(line);
		stack_clear(stack_b);
		error_exit(stack_a, NULL);
	}
	get_instruct(line, stack_a, stack_b);
	free(line);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	stack_a = parse_arguments(ac, av);
	if (!stack_a)
		return (0);
	line = get_next_line(0);
	while ((line))
	{
		instructions_loop(line, &stack_a, &stack_b);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
