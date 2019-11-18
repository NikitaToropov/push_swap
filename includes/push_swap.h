#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // don't forget!!!!!!!!

typedef struct		s_stack
{
	size_t			size;
	size_t			pos;
	int				*val;
}					t_stack;

int					ft_atoi(const char *str)

void				ft_swap(int *a, int *b);
int					ft_rev_rotate(t_stack *s);
int					ft_rotate(t_stack *s);

char				*ft_int_arr(char *str, size_t len);

#endif