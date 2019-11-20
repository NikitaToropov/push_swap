#include "push_swap.h"

void	ft_one_step_sort(t_stack *a, t_stack *b)
{
	if (a->min == a->pos)
	{
		ft_push_in_first(b, a);
	}
	else if (a->max == a->pos)
	{
		ft_rev_rotate(a);
	}
	else if (a->pos > 0 && a->val[a->pos] > a->val[a->pos - 1])
	{
		swft_swap(a);
	}
	// else if (a->min && a->min < (a->pos - a->max) && a->min < (a->max + 1))
	// {
	// 	ft_;
	// }
}

void	ft_sorting(t_stack *a, t_stack *b)
{
	if (a->min == a->pos)
	// rotate;
	// rev_rotate;
	while (!ft_it_is_sorted(a->val, a->pos))
	{
		ft_one_step_sort(a, b);
	}
	if (a->val[a->pos] == a->val[a->pos - 1])
	if (a->min == (a->pos - 1) || a->min == 0)
}