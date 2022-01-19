/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:20:44 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/18 21:20:46 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*stack);
	tmp2 = (*stack)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	(*stack) = tmp2;
}

void	rotate_stack(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = lstlast(*stack);
	tmp2 = (*stack)->next;
	tmp1->next = (*stack);
	tmp1->next->next = NULL;
	(*stack) = tmp2;
}

void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*stack);
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp2 = lstlast(*stack);
	tmp1->next = NULL;
	tmp2->next = (*stack);
	(*stack) = tmp2;
}

void	pop_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	if (tmp->next != NULL)
	{
		tmp_next = tmp->next;
		free(tmp);
		*stack = tmp_next;
	}
	else
	{
		free(tmp);
		*stack = NULL;
	}
}
