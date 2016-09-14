/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:18:45 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/08 14:51:55 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(long int nb)
{
	long int n;
	long int f;
	int sign;

	f = 1;
	sign = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		sign = -1;
	}
	n = nb * sign;
	while (n >= 10)
	{
		n /= 10;
		f *= 10;
	}
	n = nb * sign;
	while (f > 0)
	{
		ft_putchar((n / f) + '0');
		n %= f;
		f /= 10;
	}
}
