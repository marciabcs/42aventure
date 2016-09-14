/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:39:07 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/08 17:12:33 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int temp1;
	int temp2;

	temp1 = nb;
	temp2 = 1;
	while (temp1 >= 10)
	{
		temp2 *= 10;
		temp1 /= 10;
	}
	temp1 = nb;
	ft_putchar('[');
	while (temp2 > 0)
	{
		ft_putchar((temp1 / temp2) + '0');
		temp1 %= temp2;
		temp2 /= 10;
	}
	ft_putchar(']');
	ft_putchar(' ');
}

int		ft_putligne(char *table, char *c, int n, int i)
{
	int a;

	if (table[i] != c[0])
		return (1);
	i++;
	a = 1;
	if (n > 1)
	{
		while (a <= n - 2)
		{
			if (table[i] != c[1])
				return (1);
			a++;
			i++;
		}
		if (table[i] != c[2])
			return (1);
	}
	return (0);
}
