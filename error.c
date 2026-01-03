#include "push_swap.h"


void arr_clear(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
}

void error_exit(t_stack **stack_a, char **split_args)
{
    stack_clear(stack_a);
    arr_clear(split_args);

}