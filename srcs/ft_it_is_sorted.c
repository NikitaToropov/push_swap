/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_it_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:10:15 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/02 12:10:17 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_a_is_sorted(int *arr, int len)
{
	int		i;

	i = 1;
	while (i <= len)
	{
		if (arr[i] > arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int			ft_b_is_sorted(int *arr, int len)
{
	int		i;

	i = 1;
	if (!len)
		return (0);
	while (i <= len)
	{
		if (arr[i] < arr[i - 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
