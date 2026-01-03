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

    raw_str = join_args(ac, av);
    split_args = ft_split(raw_str, " \t");
    free(raw_str);
    if (!split_args)
        return (NULL);
    i = 0;
    while (split_args[i])
    {
        if (check_if_number(split_args[i]))
        {
            error_exit(&stack_a, split_args); // Passes the full array to clean up
            return (NULL);
        }
        
        num = ft_atol(split_args[i]);
        
        // Uncomment your validation checks!
        if (num > 2147483647 || num < -2147483648 || is_duplicate(stack_a, num))
        {
            error_exit(&stack_a, split_args);
            return (NULL);
        }

        stack_add_back(&stack_a, stack_new((int)num));
        // REMOVED: free(split_args[i]);  <-- Don't free here!
        i++;
    }
    
    free_split(split_args); // Free everything at once on success
    return (stack_a);
}