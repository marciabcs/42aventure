/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:14:09 by mouaret           #+#    #+#             */
/*   Updated: 2015/12/01 19:05:18 by mouaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_input(int sudoku_entree[9][9], int argc, char **argv);
void	ft_affichage(int grille[9][9]);
int		ft_est_valide(int grille[9][9], int position);
int		ft_grillecorrecte(int grille[9][9]);

int		ft_sudoku(int argc, char **argv)
{
	int grille[9][9];
	int err;

	err = ft_input(grille, argc, argv);
	if (err)
		return (1);
	err = ft_grillecorrecte(grille);
	if (!err)
		return (1);
	err = ft_est_valide(grille, 0);
	if (!err)
		return (1);
	ft_affichage(grille);
	return (0);
}

int		main(int argc, char **argv)
{
	int res;

	res = ft_sudoku(argc, argv);
	return (res);
}
