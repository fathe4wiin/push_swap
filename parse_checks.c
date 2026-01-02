#include "push_swap.h"


int check_if_number(char *str)
{
    int i;

    i = 0;

    /*
    ** TODO: check if i need to check for plus sign 
    */
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i])
    {
        if (str[i] <= '0' || str[i] >= '9')
            return (1);
        i++;
    }
    return 0;
}

int is_duplicate(t_stack *stack_a, long num)
{
    while(stack_a)
    {
        if (stack_a->value == num)
            return 1;
        stack_a = stack_a->next;
    }
    return 0;
}


