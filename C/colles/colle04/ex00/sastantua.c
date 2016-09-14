/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 10:24:09 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/12 14:28:49 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LINE nb_ligne_or_column(1, size)
#define COL nb_ligne_or_column(3, size)

void	ft_putchar(char c);

void	write_nchar(int n, char c)
{
	int i;

	i = 0;
	while (i++ < n)
		ft_putchar(c);
}

void	write_ligne(int nb_space, int nb_star, int nb_door, int handle)
{
	write_nchar(nb_space, ' ');
	ft_putchar('/');
	if (nb_door != 0)
	{
		nb_star = nb_star / 2;
		write_nchar(nb_star, '*');
		if (handle)
		{
			write_nchar(nb_door - 1, '|');
			ft_putchar('$');
			ft_putchar('|');
		}
		else
			write_nchar(nb_door, '|');
		write_nchar(nb_star, '*');
		ft_putchar('\\');
	}
	else
	{
		write_nchar(nb_star, '*');
		ft_putchar('\\');
	}
	ft_putchar('\n');
}

int		nb_ligne_or_column(int choice, int size)
{
	int i;
	int c;
	int ligne;
	int column;
	int col_begin;

	i = 1;
	ligne = 0;
	column = -3;
	c = 6;
	col_begin = 3;
	while (i <= size)
	{
		ligne = ligne + (i + 2);
		if (i > 1)
			col_begin = column + c;
		column = col_begin + ((i + 2) - 1) * 2;
		c = (i > 1 && i % 2 != 0) ? c + 2 : c;
		i++;
	}
	if (choice == 1)
		return (ligne);
	return ((choice == 4) ? col_begin : column);
}

void	init_line(int i, int size, int sizedoor, int c)
{
	int nb_star;
	int nb_space;
	int nb_door;
	int handle;

	nb_space = (COL - c) / 2;
	handle = 0;
	if (i <= (LINE - sizedoor))
	{
		nb_star = c - 2;
		nb_door = 0;
		write_ligne(nb_space, nb_star, nb_door, handle);
	}
	else
	{
		nb_star = c - 2 - sizedoor;
		nb_door = sizedoor;
		if ((i == (LINE - (sizedoor / 2))) && (sizedoor >= 5))
		{
			handle = 1;
			nb_door = nb_door - 1;
		}
		write_ligne(nb_space, nb_star, nb_door, handle);
	}
}

void	sastantua(int size)
{
	int sizedoor;
	int i;
	int l;
	int c;
	int step;

	if (size > 0)
	{
		step = 1;
		l = 1;
		sizedoor = (size % 2 == 0) ? size - 1 : size;
		i = 1;
		while (i <= LINE)
		{
			c = (l == 1) ? nb_ligne_or_column(4, step) : c + 2;
			init_line(i++, size, sizedoor, c);
			if (l == (step + 2))
			{
				step++;
				l = 1;
			}
			else
				l++;
		}
	}
}
