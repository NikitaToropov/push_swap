#include "push_swap.h"

void			print_stacks(t_stack *a, t_stack *b)
{
	int			i;
	
	printf("-----------------------------------\n");
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

void		ft_sort_three(t_stack *a)
{
	if (ft_a_is_sorted(a->val, a->pos))
		return ;
	if (a->max == 0)
		ft_swap(a);
	else if (a->max == 2 && a->min == 0)
	{
		ft_swap(a);
		ft_rev_rotate(a);
	}
	else if (a->max == 2)
		ft_rotate(a);
	else if (a->min == 0)
	{
		ft_swap(a);
		ft_rotate(a);
	}
	else
		ft_rev_rotate(a);
}

void			ft_new_sorting(t_stack *a, t_stack *b)
{
	while (a->pos > 2)
	{
		ft_push_in_first(b, a);
	}

	ft_sort_three(a);
	if (b->pos != -1)
		ft_smart_insert_sort(a, b);
}
