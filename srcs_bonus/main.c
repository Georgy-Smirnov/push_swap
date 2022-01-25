/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:59:25 by kjaco             #+#    #+#             */
/*   Updated: 2022/01/19 09:59:27 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_stack(int *stack_a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack_a[i] == stack_a[size])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char**argv)
{
	t_all	*all;
	int		i;

	i = 0;
	if (argc == 1)
		return (!write(1, "./checker ${ARG}\n", 17));
	all = init_struct(argc);
	all = init_struct(argc);
	while (i < all->size)
	{
		all->arr[i] = ft_atoi(argv[i + 1]);
		if (all->arr[i] == 0 && (argv[i + 1][0] != 48 || argv[i + 1][1] != 0))
			return (step_error(all));
		if (check_stack(all->arr, i))
			return (step_error(all));
		if (push_stack_end(&(all->a), all->arr[i]))
			return (allfree(all));
		++i;
	}
	start_read(all);
	allfree(all);
}
