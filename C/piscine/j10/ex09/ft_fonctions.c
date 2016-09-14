/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:10:25 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/08 16:04:38 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def_ex09.h"

void	ft_add(char *ca, char *cb)
{
	long int a;
	long int b;

	a = ft_atoi(ca);
	b = ft_atoi(cb);
	ft_putnbr(a + b);
	ft_putchar('\n');
}

void	ft_sub(char *ca, char *cb)
{
	long int a;
	long int b;

	a = ft_atoi(ca);
	b = ft_atoi(cb);
	ft_putnbr(a - b);
	ft_putchar('\n');
}

void	ft_mul(char *ca, char *cb)
{
	long int a;
	long int b;

	a = ft_atoi(ca);
	b = ft_atoi(cb);
	ft_putnbr(a * b);
	ft_putchar('\n');
}

void	ft_div(char *ca, char *cb)
{
	long int a;
	long int b;

	a = ft_atoi(ca);
	b = ft_atoi(cb);
	if (b == 0)
		ft_putstr("Stop: division by zero");
	else
		ft_putnbr(a / b);
	ft_putchar('\n');
}

void	ft_mod(char *ca, char *cb)
{
	long int a;
	long int b;

	a = ft_atoi(ca);
	b = ft_atoi(cb);
	if (b == 0)
		ft_putstr("Stop: modulo b zero");
	else
		ft_putnbr(a % b);
	ft_putchar('\n');
}
