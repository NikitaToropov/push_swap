/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_alloc_and_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:11:10 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/10 09:16:55 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stacks(t_stack *a, t_stack *b)
{
	if ((a)->val)
		free((a)->val);
	if ((b)->val)
		free((b)->val);
	free(a);
	free(b);
}

void	ft_make_two_stacks(t_stack **a, t_stack **b, int *arr, int len)
{
	if (!((*a) = (t_stack*)malloc(sizeof(t_stack))) ||
	!((*b) = (t_stack*)malloc(sizeof(t_stack))) ||
	!((*b)->val = (int*)malloc(sizeof(int) * len)))
		exit(1);
	(*a)->val = arr;
	(*a)->size = len;
	(*a)->pos = len - 1;
	(*a)->r = 0;
	(*a)->rr = 0;
	ft_find_max_min(*a);
	(*b)->size = len;
	(*b)->pos = -1;
	(*b)->r = 0;
	(*b)->rr = 0;
	ft_find_max_min(*b);
	while (len--)
		(*b)->val[len] = 0;
}
