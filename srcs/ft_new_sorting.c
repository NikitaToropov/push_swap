#include "push_swap.h"

static void		ft_print_ops(t_ops *ops)
{
	int			i;

	i = 0;
	while (i <= ops->pos)
	{
		if (ops->str[i] == SA)
			write(1, "SA\n", 3);
		if (ops->str[i] == SB)
			write(1, "SB\n", 3);
		if (ops->str[i] == SS)
			write(1, "SS\n", 3);
		if (ops->str[i] == PA)
			write(1, "PA\n", 3);
		if (ops->str[i] == PB)
			write(1, "PB\n", 3);
		if (ops->str[i] == RA)
			write(1, "RA\n", 3);
		if (ops->str[i] == RB)
			write(1, "RB\n", 3);
		if (ops->str[i] == RR)
			write(1, "RR\n", 3);
		if (ops->str[i] == RRA)
			write(1, "RRA\n", 4);
		if (ops->str[i] == RRB)
			write(1, "RRB\n", 4);
		if (ops->str[i] == RRR)
			write(1, "RRR\n", 4);
		i++;
	}
}

void			print_stacks(t_stack *a, t_stack *b)
{
	int			i;
	
	printf("+++++++++++ JUST DELIMETER +++++++++\n");
	i = a->size - 1;
	while (i >= 0)
	{
		printf("%-8i%-5i%i\n", i, a->val[i], b->val[i]);
		i--;
	}
	printf("-----------------------------------\n");
	printf("max     %-5i%i\n", a->max, b->max);
	printf("min     %-5i%i\n", a->min, b->min);
	printf("size    %-5i%i\n", a->size, b->size);
	printf("pos     %-5i%i\n", a->pos, b->pos);
	printf("r       %-5i%i\n", a->r, b->r);
	printf("rr      %-5i%i\n", a->rr, b->rr);
	printf("====================================\n");
}

void			ft_new_sorting(t_stack *a, t_stack *b)
{
	t_ops		*ops;
	// int			median;

	ops = ft_init_ops((unsigned int)(a->size * 2));
	// median = ft_find_median(a);
	while (a->pos > 2)
	{
		if (ops->pos == (int)(ops->size - 1))
			ops->str = ft_realloc(ops->str, (size_t)(ops->size *= 2));
		ft_push_in_first(b, a);
		ops->str[(ops->pos += 1)] = PB;
	}
	if (ops->pos == (int)(ops->size - 1))
		ops->str = ft_realloc(ops->str, (size_t)(ops->size *= 2));
	if ((!ft_a_is_sorted(a->val, a->pos) && a->pos < 2) ||
	(a->min == a->pos & a->max != 0) ||
	(a->max == 0 && a->min != a->pos) || (a->max == a->pos && a->min == 0))
	{
		ops->str[(ops->pos += 1)] = SA;
		ft_swap(a);
	}
	ft_smart_insert_sort(a, b, ops);
	ft_free_stacks(a, b);
	ft_print_ops(ops);
	ft_free_ops(&ops);
}
