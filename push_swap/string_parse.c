#include "push_swap.h"

static int		*ft_free_and_return_null(int **i)
{
	free(*i);
	return (NULL);
}

static int		ft_is_it_space(char c)
{
	if ((c >= 9 && c <=13) || c == 32)
		return (1);
	return (0);
}

static int		ft_dup_detector(int *arr, size_t len)
{
	size_t		a;
	size_t		b;
	
	a = 0;
	while (a < len)
	{
		b = a + 1;
		while (b < len)
			if (arr[a] == arr[b++])
				return (1);
		a++;
	}
	return (0);
}

static size_t	ft_len_int_arr(char *str)
{
	size_t		i;

	i = 0;
	while (*str)
	{
		while (ft_is_it_space(*str))
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

int				*ft_int_arr(char *str)
{
	int			*arr;
	size_t		len;
	size_t		i;

	if (!(len = ft_len_int_arr(str)))
		return (NULL);
	if (!(arr = (int*)malloc(sizeof(int) * len)))
		exit (1);
	i = 0;
	while (*str && i < len)
	{
		while (ft_is_it_space(*str))
			str++;
		if (((arr[i] = ft_atoi(str)) == -1 && *str != '-') ||
		(arr[i] == 0 && *str == '-'))
			return (ft_free_and_return(&arr));
		while (*str && ft_is_it_space(*str))
			str++;
	}
	if (ft_dup_detector(arr, len))
		return (ft_free_and_return_null(&arr));
	return (arr);
}