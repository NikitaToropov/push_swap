#include "push_swap.h"

static size_t	ft_len_int_arr(char *str)
{
	size_t		i;

	i = 0;
	while (*str)
	{
		while (*str && ((*str >= 9 && *str <=13) ||
		*str == 32 || *str == '-' || *str == '+'))
			str++;
		if (!(*str) || (*str < '0' || *str > '9'))
			return (0);
		while (*str && *str < 9 && *str > 13 &&
		*str != 32 && *str != '-' && *str != '+')
			str++;
		i++;
	}
	return (i);
}

char		*ft_int_arr(char *str, size_t len)
{
	int		*arr;

	if (!(arr = (int*)malloc(sizeof(int) * len--)))
		exit (1);
	while (*str && len >= 0)
	{
		arr[len--] = ft_atoi(str);
		while (*str && *str < 9 && *str > 13 && *str != 32)
			str++;
	}
	return (arr);
}