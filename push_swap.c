/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:27:52 by cmissy            #+#    #+#             */
/*   Updated: 2019/12/10 11:10:05 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int c, char **v)
{
	t_stack		*a;
	t_stack		*b;
	int			*arr;
	char		*str;
	int			len;

	if (c >= 2 && (str = ft_strdup(v[1])))
	{
		len = 2;
		while (len < c)
			str = ft_strjoin_free(str, ft_strjoin("| ", v[len++]));
		if (!(arr = ft_int_arr(str, &len)) || ft_a_is_sorted(arr, (len - 1)))
		{
			free(str);
			if (!arr)
				write(1, "Error\n", 6);
			else
				free(arr);
			return (0);
		}
		free(str);
		ft_make_two_stacks(&a, &b, arr, len);
		ft_new_sorting(a, b);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
