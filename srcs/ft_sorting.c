#include "push_swap.h"

static void		ft_one_step_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int		i;

	if (a->min == a->pos && a->pos > 1)
	{
		printf("pb - 5\n");
		ops->str[(ops->pos += 1)] = PB;
		ft_push_in_first(b, a);
	}
	else if (a->min == 0)
	{
		printf("ra - 6\n");
		ops->str[(ops->pos += 1)] = RA;
		ft_rotate(a);
	}
	else if (a->pos > 0 && a->val[a->pos] > a->val[a->pos - 1])
	{
		printf("sa - 1\n");
		ops->str[(ops->pos += 1)] = SA;
		ft_swap(a);
	}
	else
	{
		ops->str[(ops->pos += 1)] = RRA;
		printf("rra - 1\n");
		ft_rev_rotate(a);
	}
	i = 0;
	while (i < a->size)
	{
		// printf("%-3i    |%i   %i\n", i, a->val[i], b->val[i]);
		i++;
	}
	printf("-------|--------------------------------------\n");

	printf("max  = |%-4i%i\n", a->max, b->max);
	printf("min  = |%-4i%i\n", a->min, b->min);
	printf("size = |%-4i%i\n", a->size, b->size);
	printf("pos  = |%-4i%i\n", a->pos, b->pos);
	printf("===========================================\n\n");
}

void	ft_sorting(t_stack *a, t_stack *b)
{
	t_ops	*ops;
	int		i;

	i = 0;
	while (i < a->size)
	{
		printf("       %i   %i\n", a->val[i], b->val[i]);
		i++;
	}
	printf("max  = |%-4i%i\n", a->max, b->max);
	printf("min  = |%-4i%i\n", a->min, b->min);
	printf("size = |%-4i%i\n", a->size, b->size);
	printf("pos  = |%-4i%i\n", a->pos, b->pos);
	printf("\n===========================================\n");
	printf("\n\n-------------------START------------------\n");
	ops = ft_init_ops((unsigned int)(a->size * 2));
	while (a->pos && !ft_it_is_sorted(a->val, a->pos))
	{
		if (ops->pos == (int)(ops->size - 1))
			ops->str = ft_realloc(ops->str, (size_t)(ops->size *= 2));
		ft_one_step_sort(a, b, ops);
	}

	i = b->pos + 1;
	while (i)
	{
		if (ops->pos == (int)(ops->size - 1))
			ops->str = ft_realloc(ops->str, (size_t)(ops->size *= 2));
		ft_push_in_first(a, b);
		ops->str[(ops->pos += 1)] = PA;
		i--;
	}
	i = 0;
	while (i < a->size)
	{
		printf("%i\n", a->val[i++]);
	}
	i = 0;
	printf("______________________________________________\n");

	while (i <= ops->pos)
	{
		if (ops->str[i] == SA)
			printf("SA\n");
		if (ops->str[i] == SB)
			printf("SB\n");
		if (ops->str[i] == SS)
			printf("SS\n");

		if (ops->str[i] == PA)
			printf("PA\n");
		if (ops->str[i] == PB)
			printf("PB\n");

		if (ops->str[i] == RA)
			printf("RA\n");
		if (ops->str[i] == RB)
			printf("RB\n");
		if (ops->str[i] == RR)
			printf("RR\n");

		if (ops->str[i] == RRA)
			printf("RRA\n");
		if (ops->str[i] == RRB)
			printf("RRB\n");
		if (ops->str[i] == RRR)
			printf("RRR\n");
		i++;
		// printf("%hhi ", ops->str[i++]);
	}
	printf("______________________________________________\n");
	printf("num of operations = %i\n", i);
	ft_free_ops(&ops);
}