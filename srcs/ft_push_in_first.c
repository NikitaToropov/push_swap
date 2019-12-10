/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_in_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:10:36 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/10 08:43:23 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_pop(t_stack *s)
{
	int		r;

	if (s->pos >= 0)
	{
		r = s->val[s->pos];
		s->val[s->pos] = 0;
		s->pos -= 1;
		ft_find_max_min(s);
		return (r);
	}
	return (0);
}

void		ft_find_max_min(t_stack *a)
{
	int		i;

	a->max = 0;
	a->min = 0;
	i = 1;
	while (i <= a->pos)
	{
		if (a->val[i] > a->val[a->max])
			a->max = i;
		if (a->val[i] < a->val[a->min])
			a->min = i;
		i++;
	}
}

int			ft_push_in_first(t_stack *a, t_stack *b)
{
	if (b->pos >= 0 && (a->pos + 1) < a->size)
	{
		a->pos += 1;
		a->val[a->pos] = ft_pop(b);
		ft_find_max_min(a);
		return (a->val[a->pos]);
	}
	return (0);
}

void		ft_push_n_times(t_stack *a, t_stack *b, int n)
{
	while (n > 0)
	{
		ft_push_in_first(a, b);
		n--;
	}
}
