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
	size_t			max;
	size_t			min;
	size_t			size;
	size_t			pos;
	int				*val;
}					t_stack;

int					ft_atoi(const char *str);
void				*ft_memalloc(size_t size);
void				*ft_realloc(void *ptr, size_t size);

// min on the top (for a)
int					ft_it_is_sorted(int *arr, size_t len);
// max on the top (for b)
int					ft_it_is_rev_sorted(int *arr, size_t len);

void		ft_sorting(t_stack *a, t_stack *b);

// void				ft_sorting(t_stack *a, t_stack *b);


// make/delit structs
void	ft_free_stacks(t_stack **a, t_stack **b);
void	ft_make_two_stacks(t_stack **a, t_stack **b, int *arr, size_t len);


// stack manipulations
void				ft_find_max_min(t_stack *a);
int					ft_swap(t_stack *s);
int					ft_push_in_first(t_stack *a, t_stack *b);
// 231 -> 123
int					ft_rev_rotate(t_stack *s);
// 312 -> 123
int					ft_rotate(t_stack *s);

// init array
int					*ft_int_arr(char *str, size_t *len);
#endif