/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:11:20 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/02 12:11:21 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		*ft_free_and_return_null(int **i)
{
	free(*i);
	return (NULL);
}

static int		ft_dup_detector(int *arr, int len)
{
	int			a;
	int			b;

	a = 0;
	while (a < len)
	{
		b = a + 1;
		while (b < len)
			if (arr[a] == arr[b++])
				return (1);
		a++;
	}
	return (0);
}

static int		ft_len_int_arr(char *str)
{
	int			i;

	i = 0;
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str == '+' || *str == '-')
			str++;
		if (*str && (*str < '0' || *str > '9'))
			return (0);
		if (*str >= '0' && *str <= '9')
			i++;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	return (i);
}

int				*ft_int_arr(char *str, int *len)
{
	int			*arr;
	int			i;

	if (!(*len = ft_len_int_arr(str)) ||
	(!(arr = (int*)malloc(sizeof(int) * *len))))
		return (NULL);
	i = *len - 1;
	while (*str && i >= 0)
	{
		while (ft_isspace(*str))
			str++;
		if (((arr[i] = ft_atoi(str)) == -1 && *str != '-') ||
		(arr[i] == 0 && *str == '-'))
			return (ft_free_and_return_null(&arr));
		else
			i--;
		while (*str && !ft_isspace(*str))
			str++;
	}
	if (ft_dup_detector(arr, *len))
		return (ft_free_and_return_null(&arr));
	return (arr);
}
