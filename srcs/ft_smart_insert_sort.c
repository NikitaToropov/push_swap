/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_insert_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:10:56 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/02 12:10:56 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_rotate_both_stacks(t_stack *a, t_stack *b, t_ops *ops)
{
	int		n;

	n = 0;
	if (a->r && b->r && (n = a->r) <= b->r)
		ft_push_op_n_times(ops, RR, n);
	else if (a->r && b->r && (n = b->r) < a->r)
		ft_push_op_n_times(ops, RR, n);
	else if (a->rr && b->rr && (n = a->rr) <= b->rr)
		ft_push_op_n_times(ops, RRR, n);
	else if (a->rr && b->rr && (n = b->rr) < a->rr)
		ft_push_op_n_times(ops, RRR, n);
	if (a->r > b->r)
		ft_push_op_n_times(ops, RA, (a->r - n));
	if (b->r > a->r)
		ft_push_op_n_times(ops, RB, (b->r - n));
	if (a->rr > b->rr)
		ft_push_op_n_times(ops, RRA, (a->rr - n));
	if (b->rr > a->rr)
		ft_push_op_n_times(ops, RRB, (b->rr - n));
	ft_rotate_n_times(a, a->r);
	ft_rotate_n_times(b, b->r);
	ft_rev_rotate_n_times(a, a->rr);
	ft_rev_rotate_n_times(b, b->rr);
}

void		ft_smart_insert_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int		p;

	while (b->pos >= 0)
	{
		p = ft_find_shorter_way(a, b);
		ft_rotate_both_stacks(a, b, ops);
		ft_push_in_first(a, b);
		ft_push_op(ops, PA);
	}
	ft_count_ops_in_a(a, a->val[a->min]);
	if (a->rr > a->r)
		a->rr = 0;
	else
		a->r = 0;
	ft_rotate_both_stacks(a, b, ops);
}
