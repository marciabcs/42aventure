/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:45:55 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/03 10:11:49 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_ultimate_div_mod(int *div, int *mod);

void	ft_putnbr(int nb)
{
	int temp1;
	int	temp2;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	temp1 = nb;
	temp2 = 1;
	while (temp1 > 10)
	{
		temp2 *= 10;
		temp1 /= 10;
	}
	temp1 = nb;
	while (temp2 > 0)
	{
		ft_putchar((temp1 / temp2) + '0');
		temp1 %= temp2;
		temp2 /= 10;
	}
}

int		main(void)
{
	int a;
	int *div;
	int b;
	int *mod;

	a = 69;
	b = 2;
	div = &a;
	mod = &b;
	ft_putnbr(*div);
	ft_putchar('\n');
	ft_putnbr(*mod);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_ultimate_div_mod(div, mod);
	ft_putnbr(*div);
	ft_putchar('\n');
	ft_putnbr(*mod);
	return (0);
}
