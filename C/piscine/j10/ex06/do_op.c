/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:48:05 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/08 15:02:15 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def_ex06.h"

void	ft_f(long int a, long int b, long int (*f)(long int, long int))
{
	ft_putnbr(f(a, b));
}

int		main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (**(argv + 2) == '+')
		ft_f(A, B, &ft_add);
	else if (**(argv + 2) == '-')
		ft_f(A, B, &ft_sub);
	else if (**(argv + 2) == '*')
		ft_f(A, B, &ft_mul);
	else if (**(argv + 2) == '/')
		if (B != 0)
			ft_f(A, B, &ft_div);
		else
			ft_putstr("Stop : division by zero");
	else if (**(argv + 2) == '%')
		if (B != 0)
			ft_f(A, B, &ft_mod);
		else
			ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(0);
	ft_putchar('\n');
	return (0);
}
