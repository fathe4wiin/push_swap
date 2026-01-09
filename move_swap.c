#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp_val;
	int	tmp_idx;

	if (!stack || !stack->next)
		return ;
	tmp_val = stack->value;
	tmp_idx = stack->index;
	stack->value = stack->next->value;
	stack->index = stack->next->index;
	stack->next->value = tmp_val;
	stack->next->index = tmp_idx;
}

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}
