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

// rotates combinations
# define R_R		0
# define RR_RR		1
# define R_RR		2
# define RR_R		3


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

int					*ft_int_arr(char *str, int *len); // 

int					ft_b_is_sorted(int *arr, int len);
int					ft_a_is_sorted(int *arr, int len);

void				ft_make_two_stacks(t_stack **a, t_stack **b, int *arr,
					int len);
void				ft_free_stacks(t_stack *a, t_stack *b);
void				ft_find_max_min(t_stack *a);
int					ft_push_in_first(t_stack *a, t_stack *b);
void				ft_push_n_times(t_stack *a, t_stack *b, int n);
// 132 -> 321
int					ft_rotate(t_stack *s);
void				ft_rotate_n_times(t_stack *s, int n);
// 213 -> 321
int					ft_rev_rotate(t_stack *s);
void				ft_rev_rotate_n_times(t_stack *s, int n);
int					ft_swap(t_stack *s);
void				ft_new_sorting(t_stack *a, t_stack *b);
void				ft_rotate_both_stacks(t_stack *a, t_stack *b, t_ops *ops);


















void				ft_count_ops_in_a(t_stack *a, int v);
int					ft_find_shorter_way(t_stack *a, t_stack *b);
void				ft_smart_insert_sort(t_stack *a, t_stack *b, t_ops *ops);
void				print_stacks(t_stack *a, t_stack *b); // traaaaaash//////////////






void				ft_push_op_n_times(t_ops *ops, char op, int n);
void				ft_push_op(t_ops *ops, char op);
t_ops				*ft_init_ops(unsigned int len);
void				ft_free_ops(t_ops **ops);

void				ft_do_ops(t_stack *a, t_stack *b);

#endif