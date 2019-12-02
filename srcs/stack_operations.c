/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:11:16 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/02 12:11:16 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_swap(t_stack *s)
{
	if (s->pos > 0)
	{
		s->val[s->pos] += s->val[s->pos - 1];
		s->val[s->pos - 1] = s->val[s->pos] - s->val[s->pos - 1];
		s->val[s->pos] -= s->val[s->pos - 1];
		ft_find_max_min(s);
		return (0);
	}
	return (1);
}

int				ft_rotate(t_stack *s)
{
	int			i;
	int			tmp;

	if (s && s->pos)
	{
		tmp = s->val[s->pos];
		i = s->pos;
		while (i-- > 0)
			s->val[i + 1] = s->val[i];
		s->val[0] = tmp;
		ft_find_max_min(s);
		return (1);
	}
	return (0);
}

void			ft_rotate_n_times(t_stack *s, int n)
{
	while (n && ft_rotate(s))
		n--;
}

int				ft_rev_rotate(t_stack *s)
{
	int			i;
	int			tmp;

	if (s && s->pos)
	{
		tmp = s->val[0];
		i = 0;
		while (i++ < s->pos)
			s->val[i - 1] = s->val[i];
		s->val[s->pos] = tmp;
		ft_find_max_min(s);
		return (1);
	}
	return (0);
}

void			ft_rev_rotate_n_times(t_stack *s, int n)
{
	while (n && ft_rev_rotate(s))
		n--;
}
