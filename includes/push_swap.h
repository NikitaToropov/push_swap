#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // don't forget!!!!!!!!

// 11 operations:
# define SA					1
# define SB					2
# define SS					3

# define PA					4
# define PB					5

# define RA					6
# define RB					7
# define RR					8

# define RRA				9
# define RRB				10
# define RRR				11

typedef struct		s_stack
{
	size_t			size;
	size_t			pos;
	int				*val;
}					t_stack;

int					ft_atoi(const char *str);
// void				ft_sorting(t_stack *a, t_stack *b);

int					ft_push_in_first(t_stack *a, t_stack *b);
void				ft_swap(int *a, int *b);
int					ft_rev_rotate(t_stack *s);
int					ft_rotate(t_stack *s);

int					*ft_int_arr(char *str);

#endif