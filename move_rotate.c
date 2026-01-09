#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	if (write(1, "ra\n", 3) == -1)
		(void)0;
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	if (write(1, "rb\n", 3) == -1)
		(void)0;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	if (write(1, "rr\n", 3) == -1)
		(void)0;
}
