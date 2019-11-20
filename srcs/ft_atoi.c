#include "push_swap.h"

int					ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	res;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + (*str++ - '0');
		if (res > 2147483647 && sign == 1)
			return (-1);
		else if (res > 2147483648 && sign == -1)
			return (0);
	}
	return ((int)(res * sign));
}