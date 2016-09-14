/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:03:35 by dcastela          #+#    #+#             */
/*   Updated: 2016/03/22 16:35:47 by dcastela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	bsq_read_first_line(int gen_pt, t_krikkit *pt)
{
	char	buf[128];
	int		i;
	char	c;

	i = 0;
	c = ' ';
	while (c != '\n')
	{
		if (read(gen_pt, &c, 1) == 0)
			return (-1);
		if (c != '\n')
			buf[i++] = c;
	}
	if (buf[0] < '0' || buf[0] > '9')
		return (-1);
	pt->full = buf[--i];
	pt->obst = buf[--i];
	pt->empty = buf[--i];
	buf[i] = '\0';
	i = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
		pt->ymax = (pt->ymax * 10) + (buf[i++] - '0');
	if (buf[i] != '\0')
		return (-1);
	return (0);
}

int	bsq_read_line(int gen_pt, t_krikkit *pt)
{
	char	c;
	char	buf[100000];
	int		alloc;

	c = ' ';
	while (c != '\n')
	{
		if ((read(gen_pt, &c, 1) < 1) || \
				(c != '\n' && c != pt->empty && c != pt->obst))
			return (-1);
		buf[pt->xmax] = c;
		pt->xmax++;
	}
	pt->xmax--;
	if ((pt->tab = (char **)malloc(sizeof(char *) * pt->ymax)) == NULL)
		return (-1);
	if ((pt->tab[0] = (char *)malloc(pt->xmax * pt->ymax)) == NULL)
		return (-1);
	alloc = 0;
	while (++alloc < pt->ymax)
		pt->tab[alloc] = pt->tab[0] + (alloc * pt->xmax);
	alloc = -1;
	while (++alloc < pt->xmax)
		pt->tab[0][alloc] = buf[alloc];
	return (0);
}

int	bsq_read_lines(int plate, t_krikkit *pt)
{
	int		nblig;
	int		nbcol;
	char	c;

	nblig = 1;
	while (nblig < pt->ymax)
	{
		if (read(plate, pt->tab[nblig], pt->xmax) != pt->xmax)
			return (-1);
		nbcol = 0;
		while (nbcol < pt->xmax)
		{
			if (pt->tab[nblig][nbcol] != pt->empty &&
				pt->tab[nblig][nbcol] != pt->obst)
				return (-1);
			nbcol++;
		}
		read(plate, &c, 1);
		if (c != '\n')
			return (-1);
		nblig++;
	}
	return (0);
}

int	bsq_read_file(char *filename, t_krikkit *plateau)
{
	int		generated_plate;
	int		ret;
	char	c;

	generated_plate = 0;
	if (filename != (char *)0x00)
		if ((generated_plate = open(filename, O_RDONLY)) < 0)
			return (-1);
	if ((ret = bsq_read_first_line(generated_plate, plateau)) == 0)
		if ((ret = bsq_read_line(generated_plate, plateau)) == 0)
			if ((ret = bsq_read_lines(generated_plate, plateau)) == 0)
				if (read(generated_plate, &c, 1) != 0)
				{
					while (read(generated_plate, &c, 1) != 0)
						;
					ret = -1;
				}
	close(generated_plate);
	return (ret);
}
