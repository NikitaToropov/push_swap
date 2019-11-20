#include "push_swap.h"

static int		ft_pop(t_stack *s)
{
	int		r;

	if (s->pos)
	{
		r = s->val[s->pos];
		s->val[s->pos] = 0;
		s->pos -= 1;
		return (r);
	}
	return (0);
}

int		ft_push_in_first(t_stack *a, t_stack *b)
{
	if (b->pos && a->pos < a->size)
	{
		a->pos += 1;
		a->val[a->pos] = ft_pop(b);
		return (a->val[a->pos]);
	}
	return (0);
}


void		ft_swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}

int			ft_rev_rotate(t_stack *s)
{
	size_t 		i;
	int			tmp;

	if (s->pos > 1)
	{
		tmp = s->val[s->pos];
		i = s->pos;
		while (i-- > 0)
			s->val[i + 1] = s->val[i];
		s->val[0] = tmp;
		return (1);
	}
	return (0);
}

int			ft_rotate(t_stack *s)
{
	size_t 		i;
	int			tmp;

	if (s->pos > 1)
	{
		tmp = s->val[0];
		i = 0;
		while (i++ < s->pos)
			s->val[i - 1] = s->val[i];
		s->val[s->pos] = tmp;
		return (1);
	}
	return (0);
}
