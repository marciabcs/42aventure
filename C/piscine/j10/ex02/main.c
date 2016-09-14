/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:16:52 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/07 09:36:01 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_foreach(int *tab, int length, void (*f)(int));

int		*ft_map(int *tab, int length, int (*f)(int));

int	ft_square(int a)
{
	return (a * a);
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
	int *tab; 
	int v[]= { 5, 2, 1, 4, 3, 6 };
	int *m;

	tab = v;
	m = ft_map(tab, 6, &ft_square);
	ft_foreach(m, 6, &ft_putnbr);
	return (0);
}
