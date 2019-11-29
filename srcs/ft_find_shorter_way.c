#include "push_swap.h"

void		ft_count_ops_in_a(t_stack *a, int v)
{
	int		i;
	int		j;

	if (v > a->val[a->max])
	{
		a->r = a->pos - a->min;
		a->rr = a->min + 1;
		return ;
	}
	i = 0;
	j = a->max;
	while (i <= a->pos)
	{
		if (a->val[i] >= v && a->val[i] < a->val[j])
			j = i;
		i++;
	}
	a->r = a->pos - j;
	a->rr = j + 1;
}

static int		ft_smallest_combination(t_stack *a, t_stack *b, int *r)
{
	if (r[R_R] < r[RR_RR] && r[R_R] < r[R_RR] && r[R_R] < r[RR_R])
	{
		a->rr = 0;
		b->rr = 0;
		return (r[R_R]);
	}
	else if (r[RR_RR] < r[R_R] && r[RR_RR] < r[R_RR] && r[RR_RR] < r[RR_R])
	{
		a->r = 0;
		b->r = 0;
		return (r[RR_RR]);
	}
	else if (r[R_RR] < r[R_R] && r[R_RR] < r[RR_RR] && r[R_RR] < r[RR_R])
	{
		a->rr = 0;
		b->r = 0;
		return (r[R_RR]);
	}
	a->r = 0;
	b->rr = 0;
	return (r[RR_R]);
}

static int		ft_count_ops(t_stack *a, t_stack *b, int p)
{
	int		r[4];

	b->r = b->pos - p;
	b->rr = p + 1;
	ft_count_ops_in_a(a, b->val[p]);


	// if ((r_r = b->r) < a->r)
	if ((r[R_R] = b->r) < a->r)
		r[R_R] = a->r;
	if ((r[RR_RR] = b->rr) < a->rr)
		r[RR_RR] = a->rr;
	r[R_RR] = a->r + b->rr;
	r[RR_R] = a->rr + b->r;
	return (ft_smallest_combination(a, b, r));
}

int				ft_find_shorter_way(t_stack *a, t_stack *b)
{
	int		p;
	int		j;
	int		shorter_way;
	int		way;

	shorter_way = ft_count_ops(a, b, 0);
	j = 0;
	p = 1;
	while (p <= b->pos)
	{
		if ((way = ft_count_ops(a, b, p)) < shorter_way)
		{
			shorter_way = way;
			j = p;
		}
		p++;
	}
	ft_count_ops(a, b, j);
	return (j);
}