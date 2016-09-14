/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:15:54 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/08 15:29:39 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def_ex09.h"

void	ft_putnbr(long int nb)
{
	long int	n;
	long int	f;
	int 		sign;

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
