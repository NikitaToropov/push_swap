#include "push_swap.h"

static int		ft_pop(t_stack *s)
{
	int		r;

	if (s->val[s->pos])
	{
		r = s->val[s->pos];
		s->val[s->pos] = 0;
		if (s->pos)
			s->pos -= 1;
		ft_find_max_min(s);
		return (r);
	}
	return (0);
}

void		ft_find_max_min(t_stack *a)
{
	size_t		i;

	a->max = 0;
	a->min = 0;
	i = 1;
	while (i <= a->pos)
	{
		if (a->val[i] > a->val[a->max])
			a->max = i;
		if (a->val[i] < a->val[a->min])
			a->min = i;
		// printf("our            max  %zu\n", a->max);
		// printf("our            min  %zu\n\n", a->min);
		i++;
	}
}

int		ft_push_in_first(t_stack *a, t_stack *b)
{
	if (b->pos && a->pos < a->size)
	{
		if (a->val[a->pos])
			a->pos += 1;
		a->val[a->pos] = ft_pop(b);
		ft_find_max_min(a);
		return (a->val[a->pos]);
	}
	return (0);
}
