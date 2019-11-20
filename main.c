#include "push_swap.h"

int		main(int c, char **v)
{
	t_stack		*a;
	t_stack		*b;
	int			*arr;
	size_t		len;
	// char		*ops;

	if (c == 2)
	{
		if (!(arr = ft_int_arr(v[1], &len)))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		ft_make_two_stacks(&a, &b, arr, len);
	}
	// ops = ft_sorting(a, b);
	return (0);
}