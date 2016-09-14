/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss4_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckramer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:29:21 by ckramer           #+#    #+#             */
/*   Updated: 2016/03/02 17:29:43 by ckramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pss4.h"

int		player(char init, t_tab t)
{
	int		p;
	int		i;

	if (init == '1')
		p = ft_ai_play1(t);
	else
	{
		p = 10000;
		while (p > t.c)
		{
			write(1, "\nPlease enter which column you want to play: ", 45);
			p = read_number();
			if (p > t.c)
				write(1, "Play not valid, please try again: ", 34);
		}
	}
	if (p != 0)
	{
		while (test_play(p, t, init))
		{
			write(1, "Play not valid, please try again: ", 34);
			p = read_number();
		}
		i = test_grid(p, t);
		return (i);
	}
	return (-1);
}

char	init_sort(void)
{
	char	init;
	int		randon;

	write(1, "\nLet's start play!!\n", 20);
	write(1, "JAMES, our AI, plays with: o \n", 30);
	write(1, "YOU play with: x \n", 18);
	srand(time(NULL));
	randon = rand();
	if (randon % 2 == 0)
	{
		write(1, "\nJAMES starts the game\n", 23);
		init = '1';
	}
	else
	{
		write(1, "\nYOU start the game\n", 20);
		init = '2';
	}
	return (init);
}

void	start_game(t_tab t)
{
	int		i;
	char	init;

	init = init_sort();
	while (1)
	{
		i = player(init, t);
		if (i < 0)
			break ;
		design_grid(t);
		if (i == 2)
		{
			write(1, "\nGAME OVER!! NO WINNER!!\n", 25);
			break ;
		}
		else if (i == 1)
		{
			if (init == '1')
				write(1, "\nGAME OVER!! JAMES WON THE GAME\n", 32);
			else
				write(1, "\nGAME OVER!! YOU WON!! CONGRATULATIONS\n", 39);
			break ;
		}
		if (init == '1')
			init = '2';
		else
			init = '1';
	}
}

t_tab	init_tab(int l, int c)
{
	t_tab	t;
	int		i;
	int		j;

	t.l = l;
	t.c = c;
	t.tab = (char**)malloc(l * sizeof(char*));
	i = 0;
	while (i < l)
		t.tab[i++] = (char*)malloc(c * sizeof(char));
	i = 0;
	while (i < l)
	{
		j = 0;
		while (j < c)
			t.tab[i][j++] = 0;
		i++;
	}
	return (t);
}

int		main(void)
{
	int		lines;
	int		columns;
	t_tab	t;

	write(1, "WELCOME TO CONNECT FOUR GAME\n\n\n", 31);
	lines = 0;
	write(1, "Put 0 or any letter anytime to exit\n", 36);
	while (lines < 6)
	{
		write(1, "Please enter the number of lines: ", 34);
		lines = read_number();
		if (lines == 0)
			return (0);
		if (lines < 6)
			write(1, "Must be 6 or more, try again!\n", 30);
	}
	columns = 0;
	while (columns < 7)
	{
		write(1, "Please enter the number of columns: ", 36);
		columns = read_number();
		if (columns == 0)
			return (0);
		if (columns < 7)
			write(1, "Must be 7 or more, try again!\n", 30);
	}
	t = init_tab(lines, columns);
	design_grid(t);
	start_game(t);
	free(t.tab);
	return (0);
}
