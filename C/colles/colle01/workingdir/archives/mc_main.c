/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:27:23 by mcostaes          #+#    #+#             */
/*   Updated: 2015/11/30 17:06:03 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		input(char *c);

int		main(int argc, char **argv)
{
	int sudoku_entree[9][9];
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	while (i < 9)
	{
		str = argv[i];
		sudoku_entree[i] = input(str);
		ft_putchar('\n');
		i++;
	}
	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			ft_putchar(sudoku_entree[i][j] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}/*
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}*/	
