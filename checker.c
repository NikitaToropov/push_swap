#include "push_swap.h"

static int	ft_init_fd(char *str)
{
	int			fd;

	if ((fd = open(str, O_RDONLY)) < 0)
	{
		write(1, "cant read the file\n", 1);
		exit(1);
	}
	return (fd);
}

int		main(int c, char **v)
{
	t_stack		*a;
	t_stack		*b;
	int			*arr;
	int			len;
	int			fd;

	if (c > 1 && c < 4)
	{
		if (!(arr = ft_int_arr(v[1], &len)))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (c == 3)
			fd = ft_init_fd(v[2]);
		else
			fd = 0;
		ft_make_two_stacks(&a, &b, arr, len);
		ft_do_ops(a, b, fd);
		// ft_free_stacks(&a, &b);
		ft_free_stacks(a, b);
	}
	return (0);
}
