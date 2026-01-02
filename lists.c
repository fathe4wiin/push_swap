#include "push_swap.h"


t_stack *stack_new_node(int content)
{
    t_stack *node;
    
    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = content;
    node->index = -1;
    node->next = NULL;
    return (node);
}

void	stack_add_front(t_stack **stack, t_stack *new_node)
{
    if (!stack || !new_node)
        return ;
    new_node->next = *stack;
    *stack = new_node;
}

void stack_add_back(t_stack **stack, t_stack *new_node_node)
{
    t_stack *temp;

    if (!stack || !new_node_node)
        return;
    if (!*stack)
    {
        *stack = new_node_node;
        new_node_node->index = 0;
        return;
    }
    temp = *stack;
    while (temp->next)
        temp = temp->next;
    
    temp->next = new_node_node;
    
    new_node_node->index = temp->index + 1; 
}


void	stack_clear(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
