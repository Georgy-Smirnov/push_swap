/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:19:41 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/18 21:19:43 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*m3(t_stack *a, t_stack *b, t_stack *c)
{
	if (a->val > b->val)
	{
		if (a->val > c->val)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b->val > c->val)
			return (b);
		else
			return (c);
	}
	return (NULL);
}

t_stack	*min3(t_stack *a, t_stack *b, t_stack *c)
{
	if (a->val < b->val)
	{
		if (a->val < c->val)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b->val < c->val)
			return (b);
		else
			return (c);
	}
	return (NULL);
}

int	lstsize(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}

t_stack	*lstlast(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

t_all	*init_struct(int argc)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	if (all == NULL)
		return (NULL);
	all->arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (all->arr == NULL)
		return (NULL);
	all->a = NULL;
	all->b = NULL;
	all->size = argc - 1;
	all->size_a = 1;
	all->size_b = 1;
	all->dt.count = 0;
	all->dt.val = 0;
	return (all);
}
