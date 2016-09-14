/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss4_ai_test_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpham-an <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:44:16 by tpham-an          #+#    #+#             */
/*   Updated: 2016/03/03 12:35:40 by ckramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pss4.h"

int		test_a(t_tab t, char a, int j, int x)
{
	t.tab[j][x] = 0;
	if (a == '1')
		return (1);
	else if (a == '2')
		return (2);
	else
		return (0);
}

int		test_vert(int x, char a, t_tab t, int test)
{
	int		i;
	int		j;

	i = 1;
	j = t.l - 1;
	while (j > 0 && (t.tab[j][x]))
		j--;
	t.tab[j][x] = a;
	while ((j + i) < t.l && t.tab[j][x] == t.tab[j + i][x])
	{
		i++;
		if (i == test)
			return (test_a(t, a, j, x));
	}
	return (test_a(t, '0', j, x));
}

int		test_hor(int x, char a, t_tab t, int test)
{
	int		i;
	int		x1;
	int		y;

	i = 1;
	y = t.l - 1;
	while (y > 0 && (t.tab[y][x]))
		y--;
	x1 = x;
	t.tab[y][x1] = a;
	while ((x + i) < t.c && t.tab[y][x] == t.tab[y][x + i])
		if (++i == test)
			return (test_a(t, a, y, x1));
	if (i >= 1)
	{
		if (i != 1)
		{
			x = x + i - 1;
			i = 1;
		}
		while ((x - i) >= 0 && t.tab[y][x] == t.tab[y][x - i])
			if (++i == test)
				return (test_a(t, a, y, x1));
	}
	return (test_a(t, '0', y, x1));
}

int		test_diag_l(int x1, char a, t_tab t, int test)
{
	int		i;
	int		x;
	int		y1;
	int		y;

	i = 1;
	y = t.l - 1;
	while (y > 0 && (t.tab[y][x1]))
		y--;
	x = x1;
	y1 = y;
	t.tab[y1][x1] = a;
	while ((x - i) >= 0 && (y - i) >= 0 && t.tab[y][x] == t.tab[y - i][x - i])
	{
		i++;
		if (i == test)
			return (test_a(t, a, y1, x1));
	}
	if (i >= 1)
	{
		if (i != 1)
		{
			x = x - i + 1;
			y = y - i + 1;
			i = 1;
		}
		while ((x + i) < t.c && (y + i) < t.l && t.tab[y][x] ==
				t.tab[y + i][x + i])
		{
			i++;
			if (i == test)
				return (test_a(t, a, y1, x1));
		}
	}
	return (test_a(t, '0', y1, x1));
}

int		test_diag_r(int x1, char a, t_tab t, int test)
{
	int		i;
	int		x;
	int		y;
	int		y1;

	i = 1;
	y = t.l - 1;
	while (y > 0 && (t.tab[y][x1]))
		y--;
	x = x1;
	y1 = y;
	t.tab[y1][x1] = a;
	while ((x - i) >= 0 && (y + i) < t.l && t.tab[y][x] == t.tab[y + i][x - i])
	{
		i++;
		if (i == test)
			return (test_a(t, a, y1, x1));
	}
	if (i >= 1)
	{
		if (i != 1)
		{
			x = x - i + 1;
			y = y + i - 1;
			i = 1;
		}
		while ((x + i) < t.c && (y - i) >= 0 && t.tab[y][x] ==
				t.tab[y - i][x + i])
		{
			i++;
			if (i == test)
				return (test_a(t, a, y1, x1));
		}
	}
	return (test_a(t, '0', y1, x1));
}
