/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_algoritm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:19:24 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/18 21:33:39 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	it_is_all(t_stack *stack)
{
	while (stack)
	{
		if (stack->comp == 1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	push_b(t_all *all)
{
	t_stack	*stack;

	stack = all->a;
	while (it_is_all(all->a))
	{
		if (all->a->comp == 1)
		{
			if (push_s(&(all->a), &(all->b), all->a->val, 'b') == 1)
				return (1);
		}
		else
			r(&(all->a), 'a');
	}
	all->size_a = lstsize(all->a);
	all->size_b = lstsize(all->b);
	return (0);
}

int	do_else(t_all *all)
{
	if (lstlast(all->a)->val == all->arr[0])
	{
		if (all->a->val == all->arr[all->size -1])
		{
			write(1, "rra\n", 4);
			reverse_rotate_stack(&(all->a));
			write(1, "sa\n", 3);
			swap_stack(&(all->a));
		}
		return (0);
	}
	if (lstlast(all->a)->val != all->arr[all->size - 1])
		return (0);
	else
	{
		write(1, "rra\n", 4);
		reverse_rotate_stack(&(all->a));
		write(1, "rra\n", 4);
		reverse_rotate_stack(&(all->a));
		write(1, "sa\n", 3);
		swap_stack(&(all->a));
	}
	return (0);
}

int	sort_a(t_all *all)
{
	if (all->size_a == 2)
	{
		if (all->a->val > all->a->next->val)
		{
			write(1, "sa\n", 3);
			swap_stack(&(all->a));
		}
		return (0);
	}
	if (all->a->val == all->arr[0])
	{
		if (lstlast(all->a)->val == all->arr[all->size -1])
			return (0);
		else
		{
			write(1, "sa\n", 3);
			swap_stack(&(all->a));
			return (0);
		}
	}	
	else
		return (do_else(all));
	return (0);
}

int	continue_algoritm(t_all *all)
{
	if (push_b(all))
		return (1);
	if (sort_a(all))
		return (1);
	while (compare_stack_b(all))
	{
		if (push_stack_a(all))
			return (1);
	}
	last_rotates(all);
	return (0);
}
