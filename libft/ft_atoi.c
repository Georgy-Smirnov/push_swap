/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:28:29 by kjaco             #+#    #+#             */
/*   Updated: 2021/03/09 14:23:18 by kjaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	first_atoi(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (ft_strlen(&str[i]) > 12)
		return (-1);
	return (0);
}

long long	last_atoi(const char *str)
{
	int			i;
	long long	rezult;

	i = 0;
	rezult = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rezult *= 10;
		rezult += str[i] - 48;
		i++;
	}
	if (str[i] == 0)
		return (rezult);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	rezult;
	int			checker;

	checker = 0;
	i = first_atoi(str);
	if (i == -1)
		return (0);
	if (str[i] == '-')
	{
		checker++;
		i++;
	}
	else if (str[i] == '+')
		i++;
	rezult = last_atoi(&str[i]);
	if (checker == 1)
		rezult = -rezult;
	if (rezult < -2147483648 || rezult > 2147483647)
		return (0);
	return (rezult);
}
