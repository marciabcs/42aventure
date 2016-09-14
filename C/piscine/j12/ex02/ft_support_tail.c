/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:01:39 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/16 09:58:49 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		ft_atoi(char *str)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			number = number * 10 + (*str - '0');
		else
			return (number * sign);
		str++;
	}
	return (number * sign);
}

void	ft_read_std_in(int ac, int i)
{
	char c;

	if (i >= ac || ac == 1)
		while (1)
			read(0, &c, 1);
	if (i == 0)
		write(2, "tail: option requires an argument -c\n", 37);
}
