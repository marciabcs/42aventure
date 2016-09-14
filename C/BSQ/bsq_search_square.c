/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:15:19 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/24 16:47:02 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			obstacle(t_square sq, t_krikkit pt)
{
	int		i;
	int		tempx;
	int		tempy;

	if (sq.x >= pt.xmax || (sq.x + sq.size) >= pt.xmax)
		return (1);
	if (sq.x == -1)
		return (1);
	if (sq.y >= pt.ymax || (sq.y + sq.size) >= pt.ymax)
		return (1);
	i = 0;
	while (i <= sq.size)
	{
		tempx = sq.x + sq.size;
		tempy = sq.y + i;
		if (pt.tab[tempy][tempx] == pt.obst)
			return (1);
		tempx = sq.x + i;
		tempy = sq.y + sq.size;
		if (pt.tab[tempy][tempx] == pt.obst)
			return (1);
		i++;
	}
	return (0);
}

t_square	find_square(t_square sq, t_krikkit pt)
{
	t_square	p;

	p = sq;
	if (obstacle(sq, pt))
	{
		p.size = p.size - 1;
		return (p);
	}
	else
	{
		p.size = p.size + 1;
		return (find_square(p, pt));
	}
}

t_square	bsq_search_square(t_krikkit pt)
{
	t_square	sq;
	t_square	sqmax;
	int			x;
	int			y;

	x = 0;
	y = 0;
	sqmax = ft_square(-1, -1, 0);
	while (x < pt.xmax && y < pt.ymax)
	{
		if (pt.tab[y][x] != pt.obst)
			sq = find_square(ft_square(x, y, 1), pt);
		else
			sq = ft_square(-1, -1, 0);
		if ((sqmax.size < sq.size) || (sq.x != -1 && sqmax.x == -1))
			sqmax = sq;
		if (x != (pt.xmax - 1))
			x++;
		else
		{
			x = 0;
			y++;
		}
	}
	return (sqmax);
}
