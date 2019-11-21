#include "push_swap.h"

void	ft_free_stacks(t_stack **a, t_stack **b)
{
	if ((*a)->val)
		free((*a)->val);
	if ((*b)->val)
		free((*b)->val);
	free (*a);
	free (*b);
	a = NULL;
	b = NULL;
}

void	ft_make_two_stacks(t_stack **a, t_stack **b, int *arr, int len)
{
	if (!((*a) = (t_stack*)malloc(sizeof(t_stack))) ||
	!((*b) = (t_stack*)malloc(sizeof(t_stack))) ||
	!((*b)->val = (int*)malloc(sizeof(int) * len)))
		exit (1);
	(*a)->val = arr;
	(*a)->size = len;
	(*a)->pos = len - 1;
	ft_find_max_min(*a);

	(*b)->size = len;
	(*b)->pos = -1;
	ft_find_max_min(*b);
	while (len--)
		(*b)->val[len] = 0;
}