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
	size_t		len;
	int			*arr;

	// ft_check_the_valid(v[1]);
	if (!(len = ft_len_int_arr(v[1])))
		return (0);
	arr = ft_int_arr(v[1], len);
	ft_make_two_stacks(&a, &b, arr, len);
	return (0);
}