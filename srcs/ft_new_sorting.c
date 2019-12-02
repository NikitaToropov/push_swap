/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:11:34 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/02 12:11:54 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_print_sp_ops(char op)
{
	if (op == SA)
		write(1, "SA\n", 3);
	else if (op == SB)
		write(1, "SB\n", 3);
	else if (op == SS)
		write(1, "SS\n", 3);
	else if (op == PA)
		write(1, "PA\n", 3);
	else if (op == PB)
		write(1, "PB\n", 3);
}

static void		ft_print_r_ops(char op)
{
	if (op == RA)
		write(1, "RA\n", 3);
	else if (op == RB)
		write(1, "RB\n", 3);
	else if (op == RR)
		write(1, "RR\n", 3);
	else if (op == RRA)
		write(1, "RRA\n", 4);
	else if (op == RRB)
		write(1, "RRB\n", 4);
	else if (op == RRR)
		write(1, "RRR\n", 4);
}

static void		ft_print_ops(t_ops *ops)
{
	int			i;

	i = 0;
	while (i <= ops->pos)
	{
		ft_print_sp_ops(ops->str[i]);
		ft_print_r_ops(ops->str[i]);
		i++;
	}
}

void			print_stacks(t_stack *a, t_stack *b)
{
	int			i;

	printf("+++++++++++ JUST DELIMETER +++++++++\n");
	i = a->size - 1;
	while (i >= 0)
	{
		printf("%-8i%-5i%i\n", i, a->val[i], b->val[i]);
		i--;
	}
	printf("-----------------------------------\n");
	printf("max     %-5i%i\n", a->max, b->max);
	printf("min     %-5i%i\n", a->min, b->min);
	printf("size    %-5i%i\n", a->size, b->size);
	printf("pos     %-5i%i\n", a->pos, b->pos);
	printf("r       %-5i%i\n", a->r, b->r);
	printf("rr      %-5i%i\n", a->rr, b->rr);
	printf("====================================\n");
}

void			ft_new_sorting(t_stack *a, t_stack *b)
{
	t_ops		*ops;

	ops = ft_init_ops((unsigned int)(2));
	ft_push_op_n_times(ops, PB, (a->pos - 2));
	ft_push_n_times(b, a, (a->pos - 2));
	if ((!ft_a_is_sorted(a->val, a->pos) && a->pos < 2) ||
	(a->min == a->pos & a->max != 0) ||
	(a->max == 0 && a->min != a->pos) || (a->max == a->pos && a->min == 0))
	{
		ft_push_op(ops, SA);
		ft_swap(a);
	}
	ft_smart_insert_sort(a, b, ops);
	ft_free_stacks(a, b);
	ft_print_ops(ops);
	ft_free_ops(&ops);
}
