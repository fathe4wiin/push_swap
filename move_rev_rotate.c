#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*before_tail;

	if (!*stack || !(*stack)->next)
		return ;
	tail = *stack;
	before_tail = NULL;
	while (tail->next)
	{
		before_tail = tail;
		tail = tail->next;
	}
	before_tail->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
