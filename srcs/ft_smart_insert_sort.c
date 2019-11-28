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
		a->rr = 0;
		b->r = 0;
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

void		ft_rotate_me_baby(t_stack *a, t_stack *b, t_ops *ops)
{
	while (a->r || b->r)
	{
		if (ops->pos == (int)(ops->size - 1))
			ops->str = ft_realloc(ops->str, (size_t)(ops->size *= 2));
		if (a->r && b->r)
		{
			ft_rotate(a);
			ft_rotate(b);
			ops->str[(ops->pos += 1)] = RR;
			a->r -= 1;
			b->r -= 1;
		}
		else if (a->r)
		{
			ft_rotate(a);
			a->r -= 1;
			ops->str[(ops->pos += 1)] = RA;
		}
		else if (b->r)
		{
			ft_rotate(b);
			ops->str[(ops->pos += 1)] = RB;
			b->r -= 1;
		}
	}
}

void		ft_rev_rotate_me_baby(t_stack *a, t_stack *b, t_ops *ops)
{
	while (a->rr || b->rr)
	{
		if (ops->pos == (int)(ops->size - 1))
			ops->str = ft_realloc(ops->str, (size_t)(ops->size *= 2));
		if (a->rr && b->rr)
		{
			ft_rev_rotate(b);
			ft_rev_rotate(a);
			ops->str[(ops->pos += 1)] = RRR;
			a->rr -= 1;
			b->rr -= 1;
		}
		else if (a->rr)
		{
			ft_rev_rotate(a);
			ops->str[(ops->pos += 1)] = RRA;
			a->rr -= 1;
		}
		else if (b->rr)
		{
			ft_rev_rotate(b);
			ops->str[(ops->pos += 1)] = RRB;
			b->rr -= 1;
		}
	}
}

void		ft_smart_insert_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int		p;

	while (b->pos >= 0)
	{
		p = ft_find_shorter_way(a, b);
	
		ft_rotate_me_baby(a, b, ops);
		ft_rev_rotate_me_baby(a, b, ops);
		if (ops->pos == (int)(ops->size - 1))
			ops->str = ft_realloc(ops->str, (size_t)(ops->size *= 2));
		ft_push_in_first(a, b);
		ops->str[(ops->pos += 1)] = PA;
	}
	ft_count_ops_in_a(a, a->val[a->min]);
	if (a->r < a->rr)
		ft_rotate_me_baby(a, b, ops);
	else
		ft_rev_rotate_me_baby(a, b, ops);
}