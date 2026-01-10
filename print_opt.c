#include "push_swap.h"

static int	check_merge(char **pending, char *move)
{
	if ((ft_strcmp(*pending, "ra") == 0 && ft_strcmp(move, "rb") == 0) ||
		(ft_strcmp(*pending, "rb") == 0 && ft_strcmp(move, "ra") == 0))
		write(1, "rr\n", 3);
	else if ((ft_strcmp(*pending, "rra") == 0 && ft_strcmp(move, "rrb") == 0) ||
			(ft_strcmp(*pending, "rrb") == 0 && ft_strcmp(move, "rra") == 0))
		write(1, "rrr\n", 4);
	else if ((ft_strcmp(*pending, "sa") == 0 && ft_strcmp(move, "sb") == 0) ||
			(ft_strcmp(*pending, "sb") == 0 && ft_strcmp(move, "sa") == 0))
		write(1, "ss\n", 3);
	else
		return (0);
	free(*pending);
	*pending = NULL;
	return (1);
}

static int	check_cancel(char **pending, char *move)
{
	if ((ft_strcmp(*pending, "ra") == 0 && ft_strcmp(move, "rra") == 0) ||
		(ft_strcmp(*pending, "rra") == 0 && ft_strcmp(move, "ra") == 0) ||
		(ft_strcmp(*pending, "rb") == 0 && ft_strcmp(move, "rrb") == 0) ||
		(ft_strcmp(*pending, "rrb") == 0 && ft_strcmp(move, "rb") == 0) ||
		(ft_strcmp(*pending, "sa") == 0 && ft_strcmp(move, "sa") == 0) ||
		(ft_strcmp(*pending, "sb") == 0 && ft_strcmp(move, "sb") == 0) ||
		(ft_strcmp(*pending, "pa") == 0 && ft_strcmp(move, "pb") == 0) ||
		(ft_strcmp(*pending, "pb") == 0 && ft_strcmp(move, "pa") == 0))
	{
		free(*pending);
		*pending = NULL;
		return (1);
	}
	return (0);
}

static void	flush_pending(char **pending)
{
	if (*pending)
	{
		write(1, *pending, ft_strlen(*pending));
		write(1, "\n", 1);
		free(*pending);
		*pending = NULL;
	}
}

void	ft_put_move(char *move)
{
	static char	*pending;

	if (!move || !*move)
	{
		flush_pending(&pending);
		return ;
	}
	if (!pending)
	{
		pending = ft_strdup(move);
		return ;
	}
	if (check_merge(&pending, move))
		return ;
	if (check_cancel(&pending, move))
		return ;
	write(1, pending, ft_strlen(pending));
	write(1, "\n", 1);
	free(pending);
	pending = ft_strdup(move);
}
