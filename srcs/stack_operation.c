/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:20:37 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/18 21:20:39 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_stack(int val)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (tmp == NULL)
		return (NULL);
	tmp->val = val;
	tmp->comp = 0;
	tmp->type = 0;
	tmp->next = NULL;
	return (tmp);
}

int	push_stack_end(t_stack **stack, int val)
{
	t_stack	*tmp1;

	if (*stack == NULL)
	{
		*stack = new_stack(val);
		if (stack == NULL)
			return (1);
	}
	else
	{
		tmp1 = lstlast(*stack);
		tmp1->next = new_stack(val);
		if (tmp1->next == NULL)
			return (1);
	}
	return (0);
}

int	push_stack(t_stack **stack, int val)
{
	t_stack	*tmp1;

	if (*stack == NULL)
	{
		*stack = new_stack(val);
		if (stack == NULL)
			return (1);
	}
	else
	{
		tmp1 = new_stack(val);
		if (tmp1 == NULL)
			return (1);
		tmp1->next = *stack;
		(*stack) = tmp1;
	}
	return (0);
}
