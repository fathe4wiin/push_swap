#include "push_swap.h"



char *join_args(int ac, char **av)
{
    char *raw_str;
    char *temp;
    int i;

    i = 1;
    raw_str = ft_strdup("");
    if (!raw_str)
        return (NULL);
    while (i < ac)
    {
        temp = ft_strjoin(raw_str, av[i]);
        free(raw_str);
        raw_str = temp;
        
        temp = ft_strjoin(raw_str, " ");
        free(raw_str);
        raw_str = temp;
        i++;
    }
    return (raw_str);
}

t_stack *parse_arguments(int ac, char **av)
{
    t_stack *stack_a = NULL;
    char    *raw_str;
    char    **split_args;
    long    num;
    int     i;

    // 1. Join all args
    raw_str = join_args(ac, av);
    
    // 2. Split by space
    split_args = ft_split(raw_str, " ");
    free(raw_str); // Don't need the big string anymore

    // 3. Convert and Add to List
    i = 0;
    while (split_args[i])
    {
        if (check_if_number(split_args[i]))
        {
            error_exit(&stack_a, split_args);
            return (NULL);
        }
        
        num = ft_atol(split_args[i]); // Use long to check overflows
        
        // TODO: Check INT_MAX / INT_MIN and duplicates
        // if (num > INT_MAX || num < INT_MIN || is_duplicate(stack_a, num))
        //     error_exit();

        stack_add_back(&stack_a, stack_new((int)num));
        free(split_args[i]); // Free string after use
        i++;
    }
    free(split_args); // Free the array pointer
    return (stack_a);
}