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
	printf("mod     %-5i%i\n", a->mod, b->mod);
	printf("====================================\n");
}


//////////////////////////////////////////////////////////////////////////////////////////
int			ft_way_in_a(t_stack *a, int v)
{
	int		i;

	if (v < a->val[a->pos] && v > a->val[0])
		return (0);
	i = 0;
	while (i < a->pos)
	{
		if (v < a->val[i] && v > a->val[i + 1])
			break ;
		i++;
	}
	if (i )
	if (i >= a->pos / 2)
		return (a->pos - i);
	else
		return (i + 1);
}

int			ft_count_ops(t_stack *a, t_stack *b, int p)
{
	int		steps;
	int		i;

	if (p >= b->pos / 2)
		steps = b->pos - p;
	else
		steps = b->pos + 1;

// new max or new min
	if (b->val[p] > a->val[a->max])
	{
		if (a->max >= a->pos / 2)
			steps += a->pos - a->max;
		else
			steps += a->max + 1;
	}
	else if (b->val[p] < a->val[a->min])
	{
		if (a->min >= a->pos / 2)
			steps += a->pos - a->min;
		else
			steps += a->min + 1;
	}

// others
	else
		steps += ft_way_in_a(a, a->pos[p]);
	return (steps);
}

int		ft_find_shorter_way(t_stack *a, t_stack *b)
{
	int		p;
	int		res;
	int		tmp_res;
	int		j;

	res = ft_count_ops(a, b, 0)
	p == 1;
	while (p <= b->pos)
	{
		if ((tmp_res = ft_count_ops(a, b, p)) < res)
			res = tmp_res;
		p++;
	}
	return (res);
}

void		ft_smart_insert_sort(t_stack *a, t_stack *b)
{
	int		p;
	
	p = ft_find_shorter_way(a, b);
	// ft_rotate_stack_b(b, p);
	// ft_rotate_stack_a(b, p);
	ft_push_in_first(a, b);
}
//////////////////////////////////////////////////////////////////////////////////////////

void		ft_sort_three(t_stack *a)
{
	if (ft_a_is_sorted(a))
		return ;
	if (a->max == 0)
		ft_swap(a);
	else if (a->max == 2 && a->min = 0)
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
		ft_put_in_first(a, b);
	}
	ft_sort_three(a);
	if (b->pos != -1)
		ft_smart_insert_sort(a, b);
}
