#include "push_swap.h"

static void		ft_one_step_sort(t_stack *a, t_stack *b)
{
	size_t		i;

	if (a->min == a->pos && a->pos > 1)
	{
		ft_push_in_first(b, a);
	}
	else if (a->min == 0)
	{
		printf("ra\n");
		ft_rotate(a);
	}
	else if (a->pos > 0 && a->val[a->pos] > a->val[a->pos - 1])
	{
		printf("sa\n");
		ft_swap(a);
	}
	else
	{
		printf("rra\n");
		ft_rev_rotate(a);
	}
	i = 0;
	while (i < a->size)
	{
		printf("%-3zu    |%i   %i\n", i, a->val[i], b->val[i]);
		i++;
	}
	printf("-------|--------------------------------------\n");

	printf("max  = |%-4zu%zu\n", a->max, b->max);
	printf("min  = |%-4zu%zu\n", a->min, b->min);
	printf("size = |%-4zu%zu\n", a->size, b->size);
	printf("pos  = |%-4zu%zu\n", a->pos, b->pos);
	printf("===========================================\n\n");
}

void	ft_sorting(t_stack *a, t_stack *b)
{
	size_t		i;

	i = 0;
	while (i < a->size)
	{
		printf("       %i   %i\n", a->val[i], b->val[i]);
		i++;
	}
	printf("max  = |%-4zu%zu\n", a->max, b->max);
	printf("min  = |%-4zu%zu\n", a->min, b->min);
	printf("size = |%-4zu%zu\n", a->size, b->size);
	printf("pos  = |%-4zu%zu\n", a->pos, b->pos);
	printf("\n===========================================\n");
	printf("\n\n-------------------START------------------\n");
	while (a->pos && !ft_it_is_sorted(a->val, a->pos))
	{
		ft_one_step_sort(a, b);
	}

	i = b->pos + 1;
	while (i)
	{
		ft_push_in_first(a, b);
		i--;
	}
	i = 0;
	while (i < a->size)
	{
		printf("%i\n", a->val[i++]);
	}
}