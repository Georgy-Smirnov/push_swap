/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_algoritm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:20:56 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/18 21:20:58 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*next_element(t_stack *tmp, t_all *all)
{
	if (tmp->next)
		return (tmp->next);
	else
		return (all->a);
}

void	right_list(t_all *all)
{
	int		i;
	int		j;
	int		count;
	t_stack	*tmp;

	i = 1;
	tmp = all->a;
	while (i < all->size)
	{
		j = i;
		count = 0;
		while (tmp->val != all->arr[i])
			tmp = next_element(tmp, all);
		while (tmp->val == all->arr[i++])
		{
			tmp = next_element(tmp, all);
			if (all->dt.count < count++)
			{
				all->dt.val = all->arr[i - count];
				all->dt.count = count;
			}
		}
		i = j + 1;
	}
}

int	no_move(t_all *all, int val)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < all->size)
	{
		if (all->arr[i] == all->dt.val)
			break ;
		i++;
	}
	while (count != all->dt.count)
	{
		if (all->arr[i] == val)
			return (1);
		i++;
		count++;
	}
	return (0);
}

int	start_algoritm(t_all *all)
{
	t_stack	*tmp;

	tmp = all->a;
	sort_array(all->arr, all->size);
	if (all->size <= 5)
	{
		if (doiflot(all) == 1)
			return (1);
	}
	else
	{
		right_list(all);
		while (tmp)
		{
			if (!(tmp->val == all->arr[0] || tmp->val == \
				all->arr[all->size - 1] || no_move(all, tmp->val)))
				tmp->comp = 1;
			tmp = tmp->next;
		}
		if (continue_algoritm(all))
			return (1);
	}
	return (0);
}
