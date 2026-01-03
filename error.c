#include "push_swap.h"

void error_exit(t_stack **stack, char **split_args)
{
    // 1. Clear the stack nodes
    if (stack && *stack)
        stack_clear(stack);

    // 2. Clear the split array (safely)
    if (split_args)
        free_split(split_args);

    // 3. Print error and exit
    write(2, "Error\n", 6);
    exit(1);
}