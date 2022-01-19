/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:19:10 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/18 21:19:12 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min_four(int a, int b, int c, int d)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;
	return (min);
}

int	min_type(int a, int b, int c, int d)
{
	int	min;

	min = min_four(a, b, c, d);
	if (a == min)
		return (1);
	if (b == min)
		return (2);
	if (c == min)
		return (3);
	if (d == min)
		return (4);
	return (0);
}

void	finish_compare(t_all *all, t_stack *stack, int count_a, int count_b)
{
	int	s1;
	int	s2;
	int	s3;
	int	s4;

	if (count_a >= count_b)
		s1 = count_a;
	else
		s1 = count_b;
	if (all->size_a - count_a >= all->size_b - count_b)
		s2 = all->size_a - count_a;
	else
		s2 = all->size_b - count_b;
	s3 = all->size_a - count_a + count_b;
	s4 = count_a + all->size_b - count_b;
	stack->comp = min_four(s1, s2, s3, s4);
	stack->type = min_type(s1, s2, s3, s4);
	stack->count_a = count_a;
	stack->count_b = count_b;
}

void	start_compare(t_stack *stack, t_all *all, int count_b)
{
	int		count_a;
	t_stack	*tmp;

	count_a = 0;
	tmp = all->a;
	while (tmp && tmp->val > stack->val)
	{
		count_a++;
		tmp = tmp->next;
	}
	while (tmp && tmp->val < stack->val)
	{
		count_a++;
		tmp = tmp->next;
	}
	if (stack->val == all->arr[0] && \
		serch_second(all->a, all->arr[1]) != -1)
		count_a = serch_second(all->a, all->arr[1]);
	if (stack->val == all->arr[all->size - 1] && \
		serch_second(all->a, all->arr[all->size - 2]) != -1)
		count_a = serch_second(all->a, all->arr[all->size - 2]) + 1;
	finish_compare(all, stack, count_a, count_b);
}

int	compare_stack_b(t_all *all)
{
	int		count;
	t_stack	*tmp;

	all->size_a = lstsize(all->a);
	all->size_b = lstsize(all->b);
	count = 0;
	tmp = all->b;
	while (tmp)
	{
		start_compare(tmp, all, count);
		count++;
		tmp = tmp->next;
	}
	return (all->size_b);
}
