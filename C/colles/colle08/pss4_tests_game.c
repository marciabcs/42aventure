/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss4_tests_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:29:19 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/03 11:54:30 by ckramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pss4.h"

int		test_vertical(int x, int y, t_tab t)
{
	int i;

	i = 1;
	while ((y + i) < t.l && t.tab[y][x] == t.tab[y + i][x])
	{
		i++;
		if (i == 4)
			return (1);
	}
	return (0);
}

int		test_horizontal(int x, int y, t_tab t)
{
	int i;

	i = 1;
	while ((x + i) < t.c && t.tab[y][x] == t.tab[y][x + i])
	{
		i++;
		if (i == 4)
			return (1);
	}
	if (i >= 1)
	{
		if (i != 1)
		{
			x = x + i - 1;
			i = 1;
		}
		while ((x - i) >= 0 && t.tab[y][x] == t.tab[y][x - i])
		{
			i++;
			if (i == 4)
				return (1);
		}
	}
	return (0);
}

int		test_diag1(int x, int y, t_tab t)
{
	int i;

	i = 1;
	while ((x - i) >= 0 && (y - i) >= 0 && t.tab[y][x] == t.tab[y - i][x - i])
	{
		i++;
		if (i == 4)
			return (1);
	}
	if (i >= 1)
	{
		if (i != 1)
		{
			x = x - i + 1;
			y = y - i + 1;
			i = 1;
		}
		while ((x + i) < t.c && (y + i) < t.l &&
				t.tab[y][x] == t.tab[y + i][x + i])
		{
			if (++i == 4)
				return (1);
		}
	}
	return (0);
}

int		test_diag2(int x, int y, t_tab t)
{
	int i;

	i = 1;
	while ((x - i) >= 0 && (y + i) < t.l && t.tab[y][x] == t.tab[y + i][x - i])
	{
		if (++i == 4)
			return (1);
	}
	if (i >= 1)
	{
		if (i != 1)
		{
			x = x - i + 1;
			y = y + i - 1;
			i = 1;
		}
		while ((x + i) < t.c && (y - i) >= 0 &&
				t.tab[y][x] == t.tab[y - i][x + i])
		{
			if (++i == 4)
				return (1);
		}
	}
	return (0);
}

int		test_grid(int p, t_tab t)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (i < t.c)
	{
		if (!t.tab[0][i])
			flag = 1;
		if (flag)
			break ;
		i++;
	}
	if (!flag)
		return (2);
	i = t.l - 1;
	while ((i - 1) >= 0 && t.tab[i - 1][p - 1])
		i--;
	if (test_vertical(p - 1, i, t))
		return (1);
	if (test_horizontal(p - 1, i, t))
		return (1);
	if (test_diag1(p - 1, i, t))
		return (1);
	if (test_diag2(p - 1, i, t))
		return (1);
	return (0);
}
