#include "push_swap.h"

int		main(int c, char **v)
{
	t_stack		*a;
	t_stack		*b;
	int			*arr;
	int			len;
	int			i;

	if (c >= 2)
	{
		i = 0
		while (i < c)
		{
			i++;
		}
		if (!(arr = ft_int_arr(v[1], &len)))
		{
			write(1, "Error\n", 6);
			write(1, "there\n", 6);
			return (0);
		}
		if (ft_a_is_sorted(arr, len))
		{
			free(arr);
			return (0);
		}
		ft_make_two_stacks(&a, &b, arr, len);
		ft_new_sorting(a, b);
		// ft_sorting(a, b);
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