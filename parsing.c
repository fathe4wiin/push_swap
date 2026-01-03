#include "push_swap.h"

static int is_valid_arg(char *str)
{
    int i;
    int has_content;

    i = 0;
    has_content = 0;
    if (!str || !str[0])
        return (0);
    while (str[i])
    {
        if (str[i] == '\t')
            return (0);
        if (str[i] != ' ')
            has_content = 1;
        i++;
    }
    return (has_content);
}


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
        if (!is_valid_arg(av[i]))
        {
            error_exit(NULL, NULL);
            return (NULL);
        }
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
        
        if (num > INT_MAX || num < INT_MIN || is_duplicate(stack_a, num))
        {
            error_exit(&stack_a, split_args);
            return (NULL);
        }

        stack_add_back(&stack_a, stack_new((int)num));
        i++;
    }
    
    free_split(split_args); // Free everything at once on success
    return (stack_a);
}