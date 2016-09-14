/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:51:34 by dcastela          #+#    #+#             */
/*   Updated: 2016/03/24 10:52:02 by dcastela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	bsq_raz_plateau(t_krikkit *pt)
{
	pt->xmax = 0;
	pt->ymax = 0;
	pt->empty = ' ';
	pt->obst = ' ';
	pt->full = ' ';
	pt->tab = NULL;
}

void	bsq_resolve_plate(t_krikkit *pt)
{
	t_square	sq;

	sq = bsq_search_square(*pt);
	bsq_write_map(sq, *pt);
}

int		main(int argc, char **argv)
{
	t_krikkit	pt;
	char		*filename;

	while (1)
	{
		filename = NULL;
		if (argc > 1)
			if ((filename = *++argv) == NULL)
				return (0);
		bsq_raz_plateau(&pt);
		if (bsq_read_file(filename, &pt) == 0)
			bsq_resolve_plate(&pt);
		else
			write(2, "map error\n", 10);
		if (pt.tab != NULL)
		{
			(pt.tab[0] != NULL) ? (free(pt.tab[0])) : (0);
			free(pt.tab);
		}
		if (filename == NULL)
			return (0);
	}
	return (0);
}
