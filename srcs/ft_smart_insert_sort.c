#include "push_swap.h"

void		ft_coint_ops_in_a(t_stack *a, int v, int *r_a, int *rr_a)
{
	int		v_a;
	int		i;
	int		j;

	if (v > a->max)
	{
		*r_a = a->pos - a->min;
		*rr_a = a->min + 1;
		return ;
	}
	i = 0;
	j = a->max;
	while (i <= a->[pos])
	{
		if (a->val[i] > v && a->val[i] < a->val[j])
			j = i;
		i++;
	}
	*r_a = a->pos - j;
	*rr_a = j + 1;
}

int			ft_count_ops(t_stack *a, t_stack *b, int p)
{
	int		r_a;
	int		rr_a;
	int		r_b;
	int		rr_b;
	int		steps

	r_b = b->pos - p;
	rr_b = p + 1;
	ft_coint_ops_in_a(a, b->val[p], &r_a, &rr_a)
	
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
		if ((tmp_res = ft_count_ops(a, b, p) < res)
			res = tmp_res;
		p++;
	}
	ft_count_ops(a, b, res);
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