/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:20:25 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/18 21:20:26 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	push_type_one(t_all *all, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < min(stack->count_a, stack->count_b))
	{
		rr(&(all->a), &(all->b));
		i++;
	}
	if (stack->count_a < stack->count_b)
	{
		while (i++ < stack->count_b)
			r(&(all->b), 'b');
	}
	else
	{
		while (i++ < stack->count_a)
			r(&(all->a), 'a');
	}
	if (push_s(&(all->a), &(all->b), stack->val, 'a') == 1)
		return (1);
	return (0);
}

int	push_type_two(t_all *all, t_stack *stack)
{
	int	i;

	i = 0;
	if (all->size_b == 1)
		all->size_b = 0;
	while (i < min(all->size_a - stack->count_a, all->size_b - \
		stack->count_b))
	{
		rev_rr(&(all->a), &(all->b));
		i++;
	}
	if (all->size_a - stack->count_a < all->size_b - stack->count_b)
	{
		while (i++ < all->size_b - stack->count_b)
			rev_r(&(all->b), 'b');
	}
	else if (all->size_b != 1)
	{
		while (i++ < all->size_a - stack->count_a)
			rev_r(&(all->a), 'a');
	}
	if (push_s(&(all->a), &(all->b), stack->val, 'a') == 1)
		return (1);
	return (0);
}

int	push_type_three(t_all *all, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->count_b)
	{
		r(&(all->b), 'b');
		i++;
	}
	i = 0;
	while (i < all->size_a - stack->count_a)
	{
		rev_r(&(all->a), 'a');
		i++;
	}
	if (push_s(&(all->a), &(all->b), stack->val, 'a') == 1)
		return (1);
	return (0);
}

int	push_type_four(t_all *all, t_stack *stack)
{
	int	i;

	i = 0;
	if (all->size_b == 1)
		all->size_b = 0;
	while (i < all->size_b - stack->count_b)
	{
		rev_r(&(all->b), 'b');
		i++;
	}
	i = 0;
	while (i < stack->count_a)
	{
		r(&(all->a), 'a');
		i++;
	}
	if (push_s(&(all->a), &(all->b), stack->val, 'a') == 1)
		return (1);
	return (0);
}
