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

int			ft_count_ops(t_stack *a, t_stack *b, int p)
{
	int		r_r;
	int		rr_rr;
	int		r_rr;
	int		rr_r;
	int		res;

	b->r = b->pos - p;
	b->rr = p + 1;
	ft_count_ops_in_a(a, b->val[p]);
	if ((r_r = b->r) < a->r)
		r_r = a->r;
	if ((rr_rr = b->rr) < a->rr)
		rr_rr = a->rr;
	r_rr = a->r + b->rr;
	rr_r = a->rr + b->r;
	
	if (r_r < rr_rr && r_r < r_rr && r_r < rr_r)
	{
		a->rr = 0;
		b->rr = 0;
		res = r_r;
	}
	else if (rr_rr < r_r && rr_rr < r_rr && rr_rr < rr_r)
	{
		a->r = 0;
		b->r = 0;
		res = rr_rr;
	}
	else if (r_rr < r_r && r_rr < rr_rr && r_rr < rr_r)
	{
		a->rr = 0;
		b->r = 0;
		res = r_rr;
	}
	else
	{
		res = rr_r;
		a->r = 0;
		b->rr = 0;
	}
	return (res);
}

int		ft_find_shorter_way(t_stack *a, t_stack *b)
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