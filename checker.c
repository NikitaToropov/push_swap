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
			str = ft_strjoin_free(str, ft_strjoin(" ", v[len++]));
		if (!(arr = ft_int_arr(str, &len)))
		{
			free(str);
			write(1, "Error\n", 6);
			return (0);
		}
		free(str);
		ft_make_two_stacks(&a, &b, arr, len);
		ft_do_ops(a, b);
		ft_free_stacks(a, b);
	}
	return (0);
}
