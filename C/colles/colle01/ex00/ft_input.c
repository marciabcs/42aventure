/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:56:02 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/01 17:37:47 by mouaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);

int		ft_test_taille_matrix(int n)
{
	if (n != 10)
		return (1);
	else
		return (0);
}

int		ft_test_taille_ligne(char **v)
{
	int i;
	int k;

	i = 0;
	while (i < 9)
	{
		k = 0;
		while (v[i + 1][k] != 0)
			k++;
		if (k != 9)
			return (1);
		i++;
	}
	return (0);
}

int		ft_testentree(int n, char **c)
{
	int		i;
	int		k;
	char	c2;

	if (ft_test_taille_matrix(n) == 1)
		return (1);
	else if (ft_test_taille_ligne(c) == 1)
		return (1);
	i = 0;
	while (i < 9)
	{
		k = 0;
		while (k < 9)
		{
			c2 = c[i + 1][k];
			if ((c2 >= '1' && c2 <= '9') || (c2 == '.'))
				k++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int		ft_input(int grille[9][9], int argc, char **argv)
{
	int i;
	int k;

	if (ft_testentree(argc, argv) == 0)
	{
		i = -1;
		while (++i < 9)
		{
			k = 0;
			while (k < 9)
			{
				if (argv[i + 1][k] == '.')
					grille[i][k] = 0;
				else
					grille[i][k] = argv[i + 1][k] - '0';
				k++;
			}
		}
	}
	else
	{
		ft_putstr("ERREUR\n");
		return (1);
	}
	return (0);
}
