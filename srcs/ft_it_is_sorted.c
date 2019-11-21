#include "push_swap.h"

// min on the top (for a)
int		ft_it_is_sorted(int *arr, int len)
{
	int		i;

	i = 1;
	while (i <= len)
	{
		if (arr[i] > arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}

// max on the top (for b)
int		ft_it_is_rev_sorted(int *arr, int len)
{
	int		i;

	i = 1;
	if (!len)
		return (0);
	while (i <= len)
	{
		if (arr[i] < arr[i - 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}