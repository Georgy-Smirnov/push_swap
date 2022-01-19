/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doiflot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:19:34 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/18 21:19:35 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	do_if_two(t_all *all)
{
	if (all->a->val > all->a->next->val)
		write(1, "sa\n", 3);
	return (0);
}

void	s(t_stack **a)
{
	write(1, "sa\n", 3);
	swap_stack(a);
}

void	do_if_three(t_all *all)
{
	if (all->a == m3(all->a, all->a->next, all->a->next->next))
	{
		if (all->a->next == min3(all->a, all->a->next, all->a->next->next))
			r(&(all->a), 'a');
		else
		{
			s(&(all->a));
			rev_r(&(all->a), 'a');
		}
	}
	else if (all->a->next == m3(all->a, all->a->next, all->a->next->next))
	{
		if (all->a == min3(all->a, all->a->next, all->a->next->next))
		{
			s(&(all->a));
			r(&(all->a), 'a');
		}
		else
			rev_r(&(all->a), 'a');
	}
	else if (all->a->next->next == m3(all->a, all->a->next, all->a->next->next))
	{
		if (all->a->next == min3(all->a, all->a->next, all->a->next->next))
			s(&(all->a));
	}
}

int	do_elsee(t_all *all)
{
	int	i;

	if (rright_list(all))
		return (0);
	i = all->size - 3;
	while (i)
	{
		if (push_s(&(all->a), &(all->b), all->a->val, 'b') == 1)
			return (1);
		i--;
	}
	do_if_three(all);
	while (compare_stack_b(all))
	{
		if (push_stack_a(all))
			return (1);
	}
	last_rotates(all);
	return (0);
}

int	doiflot(t_all *all)
{
	int	rez;

	if (all->size == 2)
		rez = do_if_two(all);
	else if (all->size == 3)
		do_if_three(all);
	else
		if (do_elsee(all) == 1)
			return (1);
	return (0);
}
