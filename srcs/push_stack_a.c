/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:19:58 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/18 21:20:00 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	last_rotates(t_all *all)
{
	t_stack	*tmp;
	int		count;

	tmp = all->a;
	count = 0;
	while (tmp)
	{
		if (tmp->val == all->arr[0])
			break ;
		count++;
		tmp = tmp->next;
	}
	if (count < all->size / 2)
		while (all->a->val != all->arr[0])
			r(&(all->a), 'a');
	else
		while (all->a->val != all->arr[0])
			rev_r(&(all->a), 'a');
}

int	start_push(t_all *all, t_stack *stack)
{
	int	rez;

	rez = 0;
	if (stack->type == 1)
		rez = push_type_one(all, stack);
	if (stack->type == 2)
		rez = push_type_two(all, stack);
	if (stack->type == 3)
		rez = push_type_three(all, stack);
	if (stack->type == 4)
		rez = push_type_four(all, stack);
	return (rez);
}

int	push_stack_a(t_all *all)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = all->b;
	min = tmp;
	while (tmp)
	{
		if (tmp->comp < min->comp)
			min = tmp;
		tmp = tmp->next;
	}
	if (start_push(all, min))
		return (1);
	return (0);
}
