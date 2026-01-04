#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "limits.h"

typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
} t_stack;

/* Stack Utils */
t_stack *stack_new(int value);
void    stack_add_back(t_stack **stack, t_stack *new_node);
t_stack *stack_last(t_stack *stack);
int     stack_size(t_stack *stack);
void    stack_add_front(t_stack **stack, t_stack *new_node);
void    stack_clear(t_stack **stack);


long ft_atol(char *str);
int check_if_number(char *str);
int is_duplicate(t_stack *stack_a, long num);
char	**ft_split(char *str, char *charset);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);



void free_split(char **split);

void error_exit(t_stack **stack_a, char **split_args);

t_stack *parse_arguments(int ac, char **av);
void assign_index(t_stack **stack);


#endif