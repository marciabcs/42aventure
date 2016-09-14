/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:20:01 by dcastela          #+#    #+#             */
/*   Updated: 2016/03/22 16:37:02 by dcastela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

typedef struct		s_square
{
	int				x;
	int				y;
	int				size;
}					t_square;

typedef struct		s_krikkit
{
	int				xmax;
	int				ymax;
	char			empty;
	char			obst;
	char			full;
	char			**tab;
}					t_krikkit;

t_square			ft_square(int px, int py, int size);
t_square			find_square_new(t_square p, t_krikkit pt);
void				bsq_write_map(t_square sq, t_krikkit pt);
t_square			bsq_search_square(t_krikkit pt);
int					bsq_read_file(char *filename, t_krikkit *pt);

#endif
