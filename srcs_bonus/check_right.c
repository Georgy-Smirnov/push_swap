/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:59:17 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/19 09:59:19 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	str_cmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str1))
	{
		if (str1[i] != str2[i])
			return (0);
		++i;
	}
	if (str2[i] != '\0')
		return (0);
	return (1);
}

int	check_right(t_all *all)
{
	t_stack	*stack;
	int		i;

	stack = all->a;
	i = 0;
	while (stack)
	{
		if (stack->val != all->arr[i])
			return (0);
		i++;
		stack = stack->next;
	}
	if (i != all->size)
		return (0);
	return (1);
}
