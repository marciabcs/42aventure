/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:16:52 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/06 15:30:23 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_foreach(int *tab, int length, void (*f)(int));

int	*ft_range(int min, int max)
{
	int *dest;
	int i;
	int rg;

	rg = max - min;
	if (min >= max)
		return ((void*)0);
	dest = (int*)malloc(sizeof(int) * (rg + 1));
	if (!dest)
		return ((void*)0);
	i = 0;
	while (i < rg)
	{
		*(dest + i) = min + i;
		i++;
	}
	*(dest + i) = 0;
	return (dest);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	temp1;
	int			temp2;
	long int	temp3;

	temp3 = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		temp3 = -temp3;
	}
	temp1 = temp3;
	temp2 = 1;
	while (temp3 >= 10)
	{
		temp2 *= 10;
		temp3 /= 10;
	}
	while (temp2 > 0)
	{
		ft_putchar((temp1 / temp2) + '0');
		temp1 %= temp2;
		temp2 /= 10;
	}
	ft_putchar(' ');
}

int		main(void)
{
	int min;
	int max;

	max = 20;
	min = 1;

	ft_foreach(ft_range(min, max), (max - min), &ft_putnbr);
	return (0);
}
