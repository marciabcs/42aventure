/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:24:34 by mouaret           #+#    #+#             */
/*   Updated: 2015/12/01 17:30:40 by mouaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_absent_lig(int k, int grille[9][9], int i)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (grille[i][j] == k)
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int		ft_absent_col(int k, int grille[9][9], int j)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grille[i][j] == k)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_absent_bloc(int k, int grille[9][9], int i, int j)
{
	int x;
	int y;

	x = i - (i % 3);
	y = j - (j % 3);
	i = x;
	while (i < x + 3)
	{
		j = y;
		while (j < y + 3)
		{
			if (grille[i][j] == k)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
