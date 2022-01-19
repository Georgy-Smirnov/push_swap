/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:18:43 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/18 21:18:48 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	rotate_stack(a);
	rotate_stack(b);
}

void	r(t_stack **a, char stack)
{
	write(1, "r", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
	rotate_stack(a);
}

void	rev_rr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}

void	rev_r(t_stack **a, char stack)
{
	write(1, "rr", 2);
	write(1, &stack, 1);
	write(1, "\n", 1);
	reverse_rotate_stack(a);
}

int	push_s(t_stack **a, t_stack **b, int val, char stack)
{
	if (stack == 'a')
	{
		write(1, "pa\n", 3);
		if (push_stack(a, val) == 1)
			return (1);
		pop_stack(b);
	}
	else
	{
		write(1, "pb\n", 3);
		if (push_stack(b, val) == 1)
			return (1);
		pop_stack(a);
	}
	return (0);
}
