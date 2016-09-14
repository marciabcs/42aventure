/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpham-an <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:26:53 by tpham-an          #+#    #+#             */
/*   Updated: 2016/02/01 15:40:00 by ckramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"

int			ft_doop(char ope, int a, int b)
{
	int			i;
	t_ptfunc	f[5];

	f[0].ope = '+';
	f[1].ope = '-';
	f[2].ope = '*';
	f[3].ope = '/';
	f[4].ope = '%';
	f[0].ptf = &ft_add;
	f[1].ptf = &ft_sub;
	f[2].ptf = &ft_mul;
	f[3].ptf = &ft_div;
	f[4].ptf = &ft_mod;
	i = 0;
	while ((i < 5) && f[i].ope)
	{
		if (f[i].ope == ope)
			return (f[i].ptf(a, b));
		i++;
	}
	return (0);
}
