#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h> // don't forget!!!!!!!!

// 11 operations:
# define SA			1
# define SB			2
# define SS			3

# define PA			4
# define PB			5

# define RA			6
# define RB			7
# define RR			8

# define RRA		9
# define RRB		10
# define RRR		11

# define MXT		22

typedef struct		s_ops
{
	unsigned int	size;
	int				pos;
	char			*str;
}					t_ops;

typedef struct		s_stack
{
	int				max;
	int				min;
	int				size;
	int				pos;
	int				r;
	int				rr;
	int				*val;
}					t_stack;

int					*ft_int_arr(char *str, int *len);

void				ft_make_two_stacks(t_stack **a, t_stack **b, int *arr, int len);
void				ft_free_stacks(t_stack **a, t_stack **b);

int					ft_b_is_sorted(int *arr, int len);
int					ft_a_is_sorted(int *arr, int len);

void				ft_find_max_min(t_stack *a);
int					ft_push_in_first(t_stack *a, t_stack *b);

// 132 -> 321
int					ft_rotate(t_stack *s);
// 213 -> 321
int					ft_rev_rotate(t_stack *s);
int					ft_swap(t_stack *s);









void				ft_smart_insert_sort(t_stack *a, t_stack *b, t_ops *ops);

void				print_stacks(t_stack *a, t_stack *b); // traaaaaash//////////////
void				ft_new_sorting(t_stack *a, t_stack *b);
void				ft_sorting(t_stack *a, t_stack *b); // traaaaaash//////////////




void		ft_rev_rotate_me_baby(t_stack *a, t_stack *b, t_ops *ops);
void		ft_rotate_me_baby(t_stack *a, t_stack *b, t_ops *ops);











t_ops				*ft_init_ops(unsigned int len);
void				ft_free_ops(t_ops **ops);

void				ft_do_ops(t_stack *a, t_stack *b, int fd);

void				ft_sorting(t_stack *a, t_stack *b);

#endif