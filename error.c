#include "push_swap.h"

void error_exit(t_stack **stack_a, char **split_args)
{
    if (stack_a && *stack_a)
        stack_clear(stack_a);
    if (split_args)
        free_split(split_args);
    write(2, "Error\n", 6);
    exit(1);
}
