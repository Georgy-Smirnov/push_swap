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

int	my_atoi(char *str)
{
	int	rez;

	if (ft_strlen(str) > 10)
		return (0);
	if (ft_strlen(str) == 10 && ft_strncmp(str, "4294967295", \
		ft_strlen(str)) > 0)
		return (0);
	rez = ft_atoi(str);
	return (rez);
}

int	main(int argc, char**argv)
{
	t_all	*all;
	int		i;

	i = 0;
	if (argc == 1)
		return (!write(1, "./checker ${ARG}\n", 19));
	all = init_struct(argc);
	while (i < all->size)
	{
		all->arr[i] = my_atoi(argv[i + 1]);
		if ((all->arr[i] == 0 && argv[i + 1][0] != \
			'0' && argv[i + 1][1] != '\0') || check_stack(all->arr, i))
		{
			write(1, "Error\n", 6);
			return (allfree(all));
		}
		if (push_stack_end(&(all->a), all->arr[i]))
			return (allfree(all));
		++i;
	}
	start_read(all);
	allfree(all);
}
