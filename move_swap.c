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

void	sa(t_stack **stack_a, int print)
{
	swap(*stack_a);
	if (print)
		ft_put_move("sa");
}

void	sb(t_stack **stack_b, int print)
{
	swap(*stack_b);
	if (print)
		ft_put_move("sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	swap(*stack_a);
	swap(*stack_b);
	if (print)
		ft_put_move("ss");
}
