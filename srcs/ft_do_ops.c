/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:09:50 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/03 13:34:52 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_all_swaps(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "SA"))
	{
		if (a->pos > 0)
			ft_swap(a);
		return (1);
	}
	else if (!ft_strcmp(op, "sb") || !ft_strcmp(op, "SB"))
	{
		if (b->pos > 0)
			ft_swap(b);
		return (1);
	}
	else if (!ft_strcmp(op, "ss") || !ft_strcmp(op, "SS"))
	{
		if (a->pos > 0)
			ft_swap(a);
		if (b->pos > 0)
			ft_swap(b);
		return (1);
	}
	return (0);
}

static int		ft_all_pushes(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strcmp(op, "pa") || !ft_strcmp(op, "PA"))
	{
		if (b->pos >= 0)
			ft_push_in_first(a, b);
		return (1);
	}
	else if (!ft_strcmp(op, "pb") || !ft_strcmp(op, "PB"))
	{
		if (a->pos >= 0)
			ft_push_in_first(b, a);
		return (1);
	}
	return (0);
}

static int		ft_all_rotates(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "RA"))
	{
		if (a->pos > 0)
			ft_rotate(a);
		return (1);
	}
	else if (!ft_strcmp(op, "rb") || !ft_strcmp(op, "RB"))
	{
		if (b->pos > 0)
			ft_rotate(b);
		return (1);
	}
	else if (!ft_strcmp(op, "rr") || !ft_strcmp(op, "RR"))
	{
		if (a->pos > 0)
			ft_rotate(a);
		if (b->pos > 0)
			ft_rotate(b);
		return (1);
	}
	return (0);
}

static int		ft_all_rev_rotates(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strcmp(op, "rra") || !ft_strcmp(op, "RRA"))
	{
		if (a->pos > 0)
			ft_rev_rotate(a);
		return (1);
	}
	if (!ft_strcmp(op, "rrb") || !ft_strcmp(op, "RRB"))
	{
		if (b->pos > 0)
			ft_rev_rotate(b);
		return (1);
	}
	if (!ft_strcmp(op, "rrr") || !ft_strcmp(op, "RRR"))
	{
		if (a->pos > 0)
			ft_rev_rotate(a);
		if (b->pos > 0)
			ft_rev_rotate(b);
		return (1);
	}
	return (0);
}

void			ft_do_ops(t_stack *a, t_stack *b)
{
	char		*op;

	while (ft_get_next_line(0, &op))
	{
		if (ft_all_swaps(a, b, op) || ft_all_pushes(a, b, op) ||
		ft_all_rotates(a, b, op) || ft_all_rev_rotates(a, b, op))
			free(op);
		else
		{
			free(op);
			write(1, "Error\n", 6);
			return ;
		}
	}
	if (a->pos == (a->size - 1) && ft_a_is_sorted(a->val, a->pos))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
