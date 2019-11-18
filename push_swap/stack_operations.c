#include "push_swap.h"

int		ft_pop(t_stack *s)
{
	int		r;

	if (s->pos)
	{
		r == s->val[s->pos];
		s->val[s->pos] = 0;
		s->pos -= 1;
		return (r);
	}
	return (0);
}

int		ft_push(t_stack *s, int r)
{
	if (s->pos < s->size)
	{
		s->pos += 1;
		s->val[s->pos] = r;
		return (r);
	}
	return (0);
}