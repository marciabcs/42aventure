/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:45:55 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/10 10:45:59 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_atoi(char *str);

void	ft_putnbr(int nb)
{
	long int temp1;
	int	temp2;
	long int temp3;

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
}

int		main(void)
{
	char	*a;
	int		b;

	a = "+2147483647";
	b = ft_atoi(a);
	ft_putnbr(b);
	ft_putchar('\n');
	return (0);
}
