/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss4_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:56:40 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/03 12:39:22 by ckramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pss4.h"

int		is_played(int l, int c, t_tab t)
{
	if (t.tab[(l - 1)][(c - 1)] == '2')
		return (2);
	else if (t.tab[(l - 1)][(c - 1)] == '1')
		return (1);
	else
		return (0);
}

void	write_line_gride(int c)
{
	int		j;

	j = 1;
	while (j <= c)
	{
		if (j <= 10 && c < 50)
			write(1, "  ", 2);
		else if (j > 10 || c >= 50)
			write(1, " ", 1);
		if (c < 50)
		{
			ft_putnbr(j);
			write(1, " ", 1);
		}
		else
		{
			if (j % 2 != 0)
				ft_putnbr(j);
			else if (j <= 10)
				write(1, " ", 1);
		}
		if (++j == c + 1)
			write(1, "\n", 1);
	}
}

void	design_grid(t_tab t)
{
	int i;
	int j;

	i = 1;
	j = 1;
	write(1, "\n\n\nHere is the grid:\n", 21);
	while (i <= t.l + 1)
	{
		j = 1;
		while (j <= t.c)
		{
			if (t.c < 50)
				write(1, ".---", 4);
			else
				write(1, ".-", 2);
			if (++j == t.c + 1)
				write(1, ".\n", 2);
		}
		j = 1;
		if (i != t.l + 1)
			while (j <= t.c)
			{
				if (t.c < 50)
					write(1, "| ", 2);
				else
					write(1, "|", 1);
				if (is_played(i, j, t) == 1)
					write(1, "o", 1);
				else if (is_played(i, j, t) == 2)
					write(1, "x", 1);
				else
					write(1, " ", 1);
				if (t.c < 50)
					write(1, " ", 1);
				if (++j == t.c + 1)
					write(1, "|\n", 2);
			}
		i++;
	}
	write_line_gride(t.c);
}

int		read_number(void)
{
	int		i;
	int		res;
	char	buffer[5];
	char	c;

	while (1)
	{
		i = 0;
		while (read(0, &c, 1))
		{
			buffer[i++] = c;
			if (c == '\n')
				break ;
		}
		if (i == 1)
			write(1, "Play not valid, please try again: ", 35);
		else
			break ;
	}
	res = ft_atoi(buffer);
	i = 0;
	while (i < 5)
		buffer[i++] = 0;
	return (res);
}

int		test_play(int p, t_tab t, char init)
{
	int i;

	if (p < 7 && p > t.c)
		return (1);
	i = 1;
	if (t.tab[0][p - 1])
		return (1);
	while ((t.l - i) >= 0 && t.tab[(t.l - i)][(p - 1)])
		i++;
	t.tab[t.l - i][p - 1] = init;
	return (0);
}
