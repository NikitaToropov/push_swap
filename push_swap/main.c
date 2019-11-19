#include "push_swap.h"

void	ft_free_stacks(t_stack *a, t_stack *b)
{
	if (a->values)
		free(a->values);
	if (b->values)
		free(b->values);
	free (a);
	free (b);
}

void	ft_make_two_stacks(t_stack **a, t_stack **b, int *arr; size_t len)
{
	if (!(*a = (t_stack*)malloc(sizeof(t_stack))) ||
	!(*b = (t_stack*)malloc(sizeof(t_stack))) ||
	!(*b->val = (int*)malloc(sizeof(int) * len)))
		exit (1);
	*a->val = arr;
	*a->size = len;
	*a->pos = 0;

	*b->size = len;
	*b->pos = 0;
	while (len--)
		*b->val[len] = 0;
}

int		main(int c, char **v)
{
	t_stack		*a;
	t_stack		*b;
	int			*arr;
	char		*ops;

	if (!(arr = ft_int_arr(v[1], len)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_make_two_stacks(&a, &b, arr, len);
	ops = ft_sorting(a, b);
	return (0);
}