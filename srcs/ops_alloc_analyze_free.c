/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_alloc_analyze_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:11:05 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/10 08:42:52 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_op_n_times(t_ops *ops, char op, int n)
{

	while (n > 0)
	{
		ft_push_op(ops, op);
		n--;
	}
}

void	ft_push_op(t_ops *ops, char op)
{
	if (ops->pos == (int)(ops->size - 1))
		if (!(ops->str = ft_realloc(ops->str, (size_t)(ops->size *= 2))))
			exit(1);
	ops->str[(ops->pos += 1)] = op;
}

t_ops	*ft_init_ops(unsigned int len)
{
	t_ops		*ops;

	if (!(ops = malloc(sizeof(t_ops))) ||
	!(ops->str = ft_memalloc((size_t)len)))
		exit(1);
	ops->size = len;
	ops->pos = -1;
	return (ops);
}

void	ft_free_ops(t_ops **ops)
{
	if ((*ops)->str)
		free((*ops)->str);
	free(*ops);
	ops = NULL;
}
