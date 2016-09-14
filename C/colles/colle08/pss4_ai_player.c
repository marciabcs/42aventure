/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss4_ai_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckramer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 09:38:33 by ckramer           #+#    #+#             */
/*   Updated: 2016/03/03 12:09:10 by ckramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pss4.h"

int		ft_ai_test_tab(int x, int test, t_tab t)
{
	char	a;
	int		i;

	a = '1';
	while (a != '3')
	{
		i = x + 1;
		while (--i >= 0)
		{
			if (t.tab[0][i] != 0 && i > 0)
				i--;
			else if (t.tab[0][i] != 0 && i == 0)
				break ;
			if (test_hor(i, a, t, test) != 0)
				return (i + 1);
			if (test_vert(i, a, t, test) != 0)
				return (i + 1);
			if (test_diag_l(i, a, t, test) != 0)
				return (i + 1);
			if (test_diag_r(i, a, t, test) != 0)
				return (i + 1);
		}
		a++;
	}
	return (0);
}

int		ft_ai_verif_tab(int test, t_tab t)
{
	int		i;
	int		k;
	char	a;

	i = t.c - 1;
	a = '2';
	while (i >= 0)
	{
		k = test_hor(i, a, t, test);
		if (k == 2)
			return (k);
		k = test_vert(i, a, t, test);
		if (k == 2)
			return (k);
		k = test_diag_l(i, a, t, test);
		if (k == 2)
			return (k);
		k = test_diag_r(i, a, t, test);
		if (k == 2)
			return (k);
		i--;
	}
	return (0);
}

t_tab	ai_init_tab(t_tab t)
{
	int		i;
	int		j;
	t_tab	n;

	n.c = t.c;
	n.l = t.l;
	n.tab = (char**)malloc(sizeof(char*) * t.l);
	i = 0;
	while (i < t.l)
		n.tab[i++] = (char*)malloc(sizeof(char) * t.c);
	i = 0;
	while (i < t.l)
	{
		j = 0;
		while (j < t.c)
		{
			n.tab[i][j] = t.tab[i][j];
			j++;
		}
		i++;
	}
	return (n);
}

int		ft_ai_play1(t_tab t)
{
	int		i;
	t_tab	n;

	n = ai_init_tab(t);
	i = ft_ai_test_tab((t.c - 1), 4, n);
	if (i == 0)
	{
		i = ft_ai_test_tab(t.c - 1, 3, n);
		if (i == 0)
		{
			i = (t.c / 2) + 1;
			while (1)
			{
				if (t.tab[0][i - 1] != 0 && i <= t.c)
					i++;
				else if (t.tab[0][i - 1] != 0 && i > 0)
					i--;
				else
					break ;
			}
		}
	}
	free(n.tab);
	return (i);
}
