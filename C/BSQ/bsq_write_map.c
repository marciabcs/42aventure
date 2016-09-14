/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:49:34 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/22 15:56:27 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_square	ft_square(int px, int py, int size)
{
	t_square res;

	res.x = px;
	res.y = py;
	res.size = size;
	return (res);
}

int			is_square(int x, int y, t_square sq)
{
	if ((x >= sq.x) && (x <= (sq.x + sq.size)))
		if ((y >= sq.y) && (y <= (sq.y + sq.size)))
			return (1);
	return (0);
}

void		bsq_write_map(t_square sq, t_krikkit pt)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= pt.xmax && j < pt.ymax)
	{
		if (is_square(i, j, sq))
			write(1, &pt.full, 1);
		else if (i == (pt.xmax))
			write(1, "\n", 1);
		else
			write(1, &pt.tab[j][i], 1);
		if (i < pt.xmax)
			i++;
		else
		{
			i = 0;
			j++;
		}
	}
}
