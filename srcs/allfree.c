/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allfree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:18:57 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/18 21:18:59 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_array(int *a, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < (size - i - 1))
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	rright_list(t_all *all)
{
	t_stack	*tmp;
	int		i;

	tmp = all->a;
	i = 0;
	while (tmp)
	{
		if (tmp->val != all->arr[i])
			return (0);
		++i;
		tmp = tmp->next;
	}
	return (1);
}

int	serch_second(t_stack *a, int val)
{
	t_stack	*tmp;
	int		count;

	tmp = a;
	count = 0;
	while (tmp)
	{
		if (tmp->val == val)
			return (count);
		count++;
		tmp = tmp->next;
	}
	return (-1);
}

int	allfree(t_all *all)
{
	t_stack	*tmp;

	tmp = all->a;
	while (tmp)
	{
		tmp = tmp->next;
		free(all->a);
		all->a = tmp;
	}
	tmp = all->b;
	while (tmp)
	{
		tmp = tmp->next;
		free(all->b);
		all->b = tmp;
	}
	free(all->arr);
	free(all);
	return (0);
}
