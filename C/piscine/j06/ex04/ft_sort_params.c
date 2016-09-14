/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:58:31 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/15 10:22:12 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_printstr(char **str, int taille)
{
	int i;

	i = 0;
	while (i < taille)
	{
		ft_putstr(str[i + 1]);
		ft_putchar('\n');
		i++;
	}
}

int		ft_trouve_max(char **str, int taille)
{
	int i;
	int j;
	int indice;

	i = 0;
	j = 0;
	indice = 0;
	while (i < taille)
	{
		if (str[indice + 1][j] < str[i + 1][j] && str[i + 1][j])
			indice = i;
		else if (str[indice + 1][j] == str[i + 1][j] && str[i + 1][j])
			j++;
		else
		{
			j = 0;
			i++;
		}
	}
	return (indice);
}

void	ft_change(char *str, int ind1, int ind2)
{
	char temp;

	temp = str[ind1];
	str[ind1] = str[ind2];
	str[ind2] = temp;
}

int		main(int argc, char **argv)
{
	int		i;
	int		taille;
	char	*temp;
	int		indice;

	taille = argc - 1;
	temp = argv[0];
	i = 0;
	while (i < taille)
	{
		indice = ft_trouve_max(argv, taille - i);
		temp = argv[taille - i];
		argv[taille - i] = argv[indice + 1];
		argv[indice + 1] = temp;
		i++;
	}
	ft_printstr(argv, taille);
	return (0);
}
