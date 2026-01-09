#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	max = -1;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	find_index_pos(t_stack *stack, int index)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}

