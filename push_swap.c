#include "push_swap.h"

int		main(int c, char **v)
{
	t_stack		*a;
	t_stack		*b;
	int			*arr;
	char		*str;
	int			len;
	int			i;

	if (c >= 2)
	{
		str = ft_strdup(v[1]);
		i = 2;
		while (i < c)
		{
			str = ft_strjoin_free(str, ft_strjoin(" ", v[i]));
			i++;
		}
		if (!(arr = ft_int_arr(str, &len)))
		{
			free(str);
			write(1, "Error\n", 6);
			return (0);
		}
			free(str);
		if (ft_a_is_sorted(arr, len))
		{
			free(arr);
			return (0);
		}
		ft_make_two_stacks(&a, &b, arr, len);
		ft_new_sorting(a, b);
		// print_stacks(a, b);
		ft_sorting(a, b);
		ft_free_stacks(&a, &b);
	}
	// if (c == 2)
	// {
	// 	if (!(arr = ft_int_arr(v[1], &len)))
	// 	{
	// 		write(1, "Error\n", 6);
	// 		write(1, "there\n", 6);
	// 		return (0);
	// 	}
	// 	if (ft_a_is_sorted(arr, len))
	// 	{
	// 		free(arr);
	// 		return (0);
	// 	}
	// 	ft_make_two_stacks(&a, &b, arr, len);
	// 	ft_new_sorting(a, b);
	// 	// ft_sorting(a, b);
	// 	ft_free_stacks(&a, &b);
	// }
	return (0);
}