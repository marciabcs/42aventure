/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:15:20 by mouaret           #+#    #+#             */
/*   Updated: 2016/02/02 23:23:25 by mouaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar2(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar2(str[i++]);
}

int		is_dig(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

void	ft_putnbr(int nb)
{
	long	nbl;

	nbl = nb;
	if (nbl < 0)
	{
		ft_putchar2('-');
		nbl = -nbl;
	}
	if (nbl >= 10)
	{
		ft_putnbr(nbl / 10);
		ft_putnbr(nbl % 10);
	}
	else
		ft_putchar2(nbl + '0');
}

int		ft_atoi(char *str)
{
	int val;
	int sign;

	while (*str == ' ' || *str == '\n' || *str == '\f' || *str == '\r' \
			|| *str == '\v' || *str == '\t')
		str++;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	val = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (*str >= '0' && *str <= '9')
			val = val * 10 + *str - '0';
		str++;
	}
	val = val * sign;
	return (val);
}
