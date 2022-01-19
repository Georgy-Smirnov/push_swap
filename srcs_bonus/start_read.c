/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:59:33 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/19 09:59:35 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	do_rev_rotate_command(char *command, t_all *all)
{
	if (str_cmp(command, "rra"))
	{
		if (all->a == NULL || all->a->next == NULL)
			return (write(1, "Error\n", 6));
		reverse_rotate_stack(&(all->a));
	}
	else if (str_cmp(command, "rrb"))
	{
		if (all->b == NULL || all->b->next == NULL)
			return (write(1, "Error\n", 6));
		reverse_rotate_stack(&(all->b));
	}
	else if (str_cmp(command, "rrr"))
	{
		if (all->b == NULL || all->b->next == NULL \
			|| all->a == NULL || all->a->next == NULL)
			return (write(1, "Error\n", 6));
		reverse_rotate_stack(&(all->a));
		reverse_rotate_stack(&(all->b));
	}
	else
		return (write(1, "Error\n", 6));
	return (0);
}

int	do_rotate_command(char *command, t_all *all)
{
	if (str_cmp(command, "ra"))
	{
		if (all->a == NULL || all->a->next == NULL)
			return (write(1, "Error\n", 6));
		rotate_stack(&(all->a));
	}
	else if (str_cmp(command, "rb"))
	{
		if (all->b == NULL || all->b->next == NULL)
			return (write(1, "Error\n", 6));
		rotate_stack(&(all->b));
	}
	else if (str_cmp(command, "rr"))
	{
		if (all->b == NULL || all->b->next == NULL \
			|| all->a == NULL || all->a->next == NULL)
			return (write(1, "Error\n", 6));
		rotate_stack(&(all->a));
		rotate_stack(&(all->b));
	}
	else
		return (do_rev_rotate_command(command, all));
	return (0);
}

int	next_command(char *command, t_all *all)
{
	if (str_cmp(command, "pa") && (all->b != NULL))
	{
		if (push_stack(&(all->a), all->b->val) == 1)
			return (1);
		pop_stack(&(all->b));
	}
	else if (str_cmp(command, "pb") && (all->a != NULL))
	{
		if (push_stack(&(all->b), all->a->val) == 1)
			return (1);
		pop_stack(&(all->a));
	}
	else
		return (do_rotate_command(command, all));
	return (0);
}

int	do_command(char *command, t_all *all)
{
	if (str_cmp(command, "sa"))
	{
		if (all->a == NULL || all->a->next == NULL)
			return (write(1, "Error\n", 6));
		swap_stack(&(all->a));
	}
	else if (str_cmp(command, "sb"))
	{
		if (all->b == NULL || all->b->next == NULL)
			return (write(1, "Error\n", 6));
		swap_stack(&(all->a));
	}
	else if (str_cmp(command, "ss"))
	{
		if (all->a == NULL || all->a->next == NULL || \
			all->b == NULL || all->b->next == NULL)
			return (write(1, "Error\n", 6));
		swap_stack(&(all->a));
		swap_stack(&(all->b));
	}
	else
		return (next_command(command, all));
	return (0);
}

int	start_read(t_all *all)
{
	char	*buffer;

	if (all->size == 1)
		return (0);
	sort_array(all->arr, all->size);
	while (get_next_line(0, &buffer))
	{
		if (do_command(buffer, all) != 0)
			return (1);
		free(buffer);
	}
	if (check_right(all))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
