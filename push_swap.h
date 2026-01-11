/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:19:13 by bfathi            #+#    #+#             */
/*   Updated: 2026/01/12 00:50:23 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "gnl/get_next_line.h"
# include "limits.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_vars
{
	int				n;
	int				middle;
	int				offset;
	int				start;
	int				end;
	int				size;
	int				down;
	int				pushed_above;
	int				pushed_below;
}					t_vars;

/*
** Stack Utils (utils/)
*/
t_stack				*stack_new(int value);
void				stack_add_back(t_stack **stack, t_stack *new_node);
t_stack				*stack_last(t_stack *stack);
int					stack_size(t_stack *stack);
void				stack_add_front(t_stack **stack, t_stack *new_node);
void				stack_clear(t_stack **stack);

/*
** Lib Utils (utils/)
*/
long				ft_atol(char *str);
char				**ft_split(char *str, char *charset);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *str);
void				ft_put_move(char *move);
void				free_split(char **split);
int					ft_issep(char c, char *sep);
int					word_count(char *str, char *sep);

/*
** Parsing (parsing/)
*/
void				error_exit(t_stack **stack_a, char **split_args);
t_stack				*parse_arguments(int ac, char **av);
int					check_if_number(char *str);
int					is_duplicate(t_stack *stack_a, long num);

/*
** Sorting (sorting/)
*/
t_stack				*sort(t_stack **stack_a);
void				sort_three(t_stack **stack_a);
void				sort_small(t_stack **stack_a, t_stack **stack_b);
void				assign_index(t_stack **stack);
int					is_sorted(t_stack *stack);

/*
** Sorting Utils (sorting/)
*/
int					find_max_index(t_stack *stack);
int					find_min_index(t_stack *stack);
int					find_index_pos(t_stack *stack, int index);
void				expanding_the_chunk(t_vars *vars);
void				find_next_target(int max_index, t_stack **stack_b,
						int *target_pos);
void				we_have_the_max(t_stack **stack_a, t_stack **stack_b,
						t_vars *vars);

/*
** Moves (moves/)
*/
void				sa(t_stack **stack_a, int print);
void				sb(t_stack **stack_b, int print);
void				ss(t_stack **stack_a, t_stack **stack_b, int print);
void				pa(t_stack **stack_a, t_stack **stack_b, int print);
void				pb(t_stack **stack_a, t_stack **stack_b, int print);
void				ra(t_stack **stack_a, int print);
void				rb(t_stack **stack_b, int print);
void				rr(t_stack **stack_a, t_stack **stack_b, int print);
void				rra(t_stack **stack_a, int print);
void				rrb(t_stack **stack_b, int print);
void				rrr(t_stack **stack_a, t_stack **stack_b, int print);

/*
** Bonus Checks (bonus/)
*/
int					is_instruct(char *instruct);
int					get_instruct(char *instruct, t_stack **stack_a,
						t_stack **stack_b);

#endif