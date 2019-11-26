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
		if (a->val[i] > v && a->val[i] < a->val[j])
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
	if ((r_r = a->r - b->r) < 0)
		r_r = b->r - a->r;
	if ((rr_rr = a->rr - b->rr) < 0)
		r_r = b->rr - a->rr;
	r_rr = b->r + a->rr;
	rr_r = b->rr + a->r;
	// print_stacks(a, b);/////////////////////////////////////////////////////////
	if ((res = r_r) < rr_rr && res < r_rr && res < rr_r)
	{
		b->rr = 0;
		a->rr = 0;
	}
	else if ((res = rr_rr) < r_r && res < r_rr && res < rr_r)
	{

		b->r = 0;
		a->r = 0;
	}
	else if ((res = r_rr) < r_r && res < rr_rr && res < rr_r)
	{
		b->rr = 0;
		a->r = 0;
	}
	else
	{
		res = rr_r;
		b->r = 0;
		a->rr = 0;
	}
	// print_stacks(a, b);/////////////////////////////////////////////////////////
	return (res);
}


int		ft_find_shorter_way(t_stack *a, t_stack *b)
{
	int		p;
	int		j;
	int		way;
	int		tmp_way;

	way = ft_count_ops(a, b, 0);
	j = 0;
	p = 1;

	while (p <= b->pos)
	{
		if ((tmp_way = ft_count_ops(a, b, p)) < way)
		{
			way = tmp_way;
			j = p;
		}
		p++;
	}

	ft_count_ops(a, b, j);
	
	return (j);
}

void		ft_smart_insert_sort(t_stack *a, t_stack *b)
{
	int		p;

	while (b->pos >= 0)
	{
		p = ft_find_shorter_way(a, b);
		while (a->r || b->r)
		{
	// IPORTANT!!!!!!! later serch combination "RA RB"
			if (a->r)
			{
				ft_rotate(a);
				a->r -= 1;
			}
			if (b->r)
			{
				ft_rotate(b);
				b->r -= 1;
			}
	// write(1, "HELLO THERE!/n", 13);
		}
		while (a->rr || b->rr)
		{
			// print_stacks(a, b);
	// IPORTANT!!!!!!! later serch combination "RRA RRB"
			if (a->rr)
			{
				ft_rev_rotate(a);
				a->rr -= 1;
			}
			if (b->rr)
			{
				ft_rev_rotate(b);
				b->rr -= 1;
			}
		}
		ft_push_in_first(a, b);
	}
	print_stacks(a, b);
}