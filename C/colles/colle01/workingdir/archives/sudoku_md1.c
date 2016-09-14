/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_md1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:53:38 by mdaoui            #+#    #+#             */
/*   Updated: 2015/11/30 20:28:33 by mdaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void	ft_putchar(char c);
void	ft_puterr(void);
void	ft_putnum(int i);
bool	absent_sur_ligne(int k, int grille[9][9], int i);
bool	absent_sur_colonne(int k, int grille[9][9], int j);
bool	absent_sur_bloc(int k, int grille[9][9], int i, int j);

void	affichage(int grille[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if ((j + 1) % 3)
			{
				ft_putnum(grille[i][j]);
				ft_putchar(' ');
			}
			else
			{
				ft_putnum(grille[i][j]);
				if (j < 8)
					ft_putchar(' ');
			}
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

bool	est_valide(int grille[9][9], int position)
{
	int i;
	int j;
	int k;

	i = position / 9;
	j = position % 9;
	k = 1;
	if (position == 9 * 9)
		return (true);
	if (grille[i][j] != 0)
		return (est_valide(grille, position + 1));
	while (k <= 9)
	{
		if (absent_sur_ligne(k, grille, i) && absent_sur_colonne(k, grille, j)
				&& absent_sur_bloc(k, grille, i, j))
		{
			grille[i][j] = k;
			if (est_valide(grille, position + 1))
				return (true);
		}
		k++;
	}
	grille[i][j] = 0;
	return (false);
}

int	main(void)
{
	int grille[9][9] =
		{
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,3,0,8,5},
			{0,0,1,0,2,0,0,0,0},
			{0,0,0,5,0,7,0,0,0},
			{0,0,4,0,0,0,1,0,0},
			{0,9,0,0,0,0,0,0,0},
			{5,0,0,0,0,0,0,7,3},
			{0,0,2,0,1,0,0,0,0},
			{0,0,0,0,4,0,0,0,9}
		};

	affichage(grille);
	ft_putchar('\n');
	est_valide(grille, 0);
	affichage(grille);
	return (0);
}
