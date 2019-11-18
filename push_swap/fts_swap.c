#include "push_swap.h"

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