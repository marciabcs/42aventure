/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss4_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckramer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:43:13 by ckramer           #+#    #+#             */
/*   Updated: 2016/03/02 17:43:17 by ckramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pss4.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nbl;

	nbl = nb;
	if (nbl < 0)
	{
		nbl = -nbl;
		ft_putchar('-');
	}
	if (nbl >= 10)
	{
		ft_putnbr(nbl / 10);
		ft_putnbr(nbl % 10);
	}
	else
		ft_putchar(nbl + '0');
}
