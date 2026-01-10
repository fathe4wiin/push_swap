#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;

    if (ac < 2)
        return (0);    
    stack_a = parse_arguments(ac, av);
    if (!stack_a)
        return (0);
    assign_index(&stack_a);
    if (!is_sorted(stack_a) && stack_size(stack_a) > 1) 
        stack_a = sort(&stack_a);
    stack_clear(&stack_a);
    ft_put_move(NULL);
    return (0);
}
