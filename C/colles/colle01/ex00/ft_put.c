/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:26:19 by mouaret           #+#    #+#             */
/*   Updated: 2015/12/01 17:31:27 by mouaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnum(int i)
{
	ft_putchar(i + '0');
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
