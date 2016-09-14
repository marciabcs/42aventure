/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:03:40 by mouaret           #+#    #+#             */
/*   Updated: 2015/12/01 18:38:50 by mouaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnum(int i);
int		ft_absent_lig(int k, int grille[9][9], int i);
int		ft_absent_col(int k, int grille[9][9], int j);
int		ft_absent_bloc(int k, int grille[9][9], int i, int j);

void	ft_affichage(int grille[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (grille[i][j])
				ft_putnum(grille[i][j]);
			else
				ft_putchar('.');
			if (j < 8)
				ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

int		ft_est_valide(int grille[9][9], int position)
{
	int i;
	int j;
	int k;

	if (position == 9 * 9)
		return (1);
	i = position / 9;
	j = position % 9;
	if (grille[i][j] != 0)
		return (ft_est_valide(grille, position + 1));
	k = 1;
	while (k <= 9)
	{
		if (ft_absent_lig(k, grille, i) && ft_absent_col(k, grille, j)
				&& ft_absent_bloc(k, grille, i, j))
		{
			grille[i][j] = k;
			if (ft_est_valide(grille, position + 1))
				return (1);
		}
		k++;
	}
	grille[i][j] = 0;
	return (0);
}

int		ligcorrecte(int grille[9][9], int lig, int j, int k)
{
	if (grille[lig][j] != 0 && j != k)
		if (grille[lig][j] == grille[lig][k])
			return (0);
	return (1);
}

int		colcorrecte(int grille[9][9], int i, int col, int k)
{
	if (grille[i][col] != 0 && i != k)
		if (grille[i][col] == grille[k][col])
			return (0);
	return (1);
}

int		ft_grillecorrecte(int grille[9][9])
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i < 9)
	{
		j = 0;
		while (j < 9)
		{
			k = 0;
			while (k < 9)
			{
				if (!ligcorrecte(grille, i, j, k)
						|| !colcorrecte(grille, j, i, k))
				{
					ft_putstr("ERREUR\n");
					return (0);
				}
				k++;
			}
			j++;
		}
	}
	return (1);
}
