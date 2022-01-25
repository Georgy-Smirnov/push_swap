/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:20:15 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/19 10:15:29 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				val;
	int				comp;
	int				type;
	int				count_a;
	int				count_b;
	struct s_stack	*next;
}					t_stack;

typedef struct s_dontouch
{
	int	val;
	int	count;
}	t_dontouch;

typedef struct s_all
{
	t_stack		*a;
	t_stack		*b;
	int			*arr;
	int			size;
	int			size_a;
	int			size_b;
	t_dontouch	dt;
}		t_all;

t_all	*init_struct(int argc);
t_stack	*lstlast(t_stack *lst);
int		lstsize(t_stack *stack);
t_stack	*new_stack(int val);
int		push_stack_end(t_stack **stack, int val);
int		push_stack(t_stack **stack, int val);
int		start_algoritm(t_all *all);
int		continue_algoritm(t_all *all);
void	swap_stack(t_stack **stack);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);
void	pop_stack(t_stack **stack);
void	rr(t_stack **a, t_stack **b);
void	r(t_stack **a, char stack);
void	rev_rr(t_stack **a, t_stack **b);
void	rev_r(t_stack **a, char stack);
int		push_s(t_stack **a, t_stack **b, int val, char stack);
int		compare_stack_b(t_all *all);
void	start_compare(t_stack *stack, t_all *all, int count_b);
int		push_stack_a(t_all *all);
int		push_type_one(t_all *all, t_stack *stack);
int		push_type_two(t_all *all, t_stack *stack);
int		push_type_three(t_all *all, t_stack *stack);
int		push_type_four(t_all *all, t_stack *stack);
void	last_rotates(t_all *all);
t_stack	*m3(t_stack *a, t_stack *b, t_stack *c);
t_stack	*min3(t_stack *a, t_stack *b, t_stack *c);
int		doiflot(t_all *all);
int		allfree(t_all *all);
int		serch_second(t_stack *a, int val);
int		rright_list(t_all *all);
int		start_read(t_all *all);
void	sort_array(int *a, int size);
int		check_right(t_all *all);
int		str_cmp(char *str1, char *str2);
int		step_error(t_all *all);

#endif
