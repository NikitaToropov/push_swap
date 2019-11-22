#include "push_swap.h"

t_ops	*ft_init_ops(unsigned int len)
{
	t_ops		*ops;

	if (!(ops = malloc(sizeof(t_ops))) ||
	!(ops->str = ft_memalloc((size_t)len)))
		exit(1);
	ops->size = len;
	ops->pos = -1;
	return (ops);
}

void	ft_free_ops(t_ops **ops)
{
	if ((*ops)->str)
		free((*ops)->str);
	free(*ops);
	ops = NULL;
}
