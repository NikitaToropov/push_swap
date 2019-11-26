#include "push_swap.h"

static int		ft_all_swaps(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "SA"))
	{
		ft_swap(a);
		return (1);
	}
	else if (!ft_strcmp(op, "sb") || !ft_strcmp(op, "SB"))
	{
		ft_swap(b);
		return (1);
	}
	else if (!ft_strcmp(op, "ss") || !ft_strcmp(op, "SS"))
	{
		ft_swap(a);
		ft_swap(b);
		return (1);
	}
	return (0);
}

static int		ft_all_pushes(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strcmp(op, "pa") || !ft_strcmp(op, "PA"))
	{
		ft_push_in_first(a, b);
		return (1);
	}
	else if (!ft_strcmp(op, "pb") || !ft_strcmp(op, "PB"))
	{
		ft_push_in_first(b, a);
		return (1);
	}
	return (0);
}

static int		ft_all_rotates(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "RA"))
	{
		ft_rotate(a);
		return (1);
	}
	else if (!ft_strcmp(op, "rb") || !ft_strcmp(op, "RB"))
	{
		ft_rotate(b);
		return (1);
	}
	else if (!ft_strcmp(op, "rr") || !ft_strcmp(op, "RR"))
	{
		ft_rotate(a);
		ft_rotate(b);
		return (1);
	}
	return (0);
}

static int		ft_all_rev_rotates(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strcmp(op, "rra") || !ft_strcmp(op, "RRA"))
	{
		ft_rev_rotate(a);
		return (1);
	}
	if (!ft_strcmp(op, "rrb") || !ft_strcmp(op, "RRB"))
	{
		ft_rev_rotate(b);
		return (1);
	}
	if (!ft_strcmp(op, "rrr") || !ft_strcmp(op, "RRR"))
	{
		ft_rev_rotate(a);
		ft_rev_rotate(b);
		return (1);
	}
	return (0);
}

void			ft_do_ops(t_stack *a, t_stack *b, int fd)
{
	char		*op;

	while (ft_get_next_line(fd, &op))
	{
		if (ft_all_swaps(a, b, op) || ft_all_pushes(a, b, op) ||
		ft_all_rotates(a, b, op) || ft_all_rev_rotates(a, b, op))
			continue ;
		else
		{
			write(1, "Error\n", 6);
			return ;
		}
	}
	if (a->pos == (a->size - 1) && ft_a_is_sorted(a->val, a->pos))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
