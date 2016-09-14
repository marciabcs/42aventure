/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:03:23 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/08 16:55:59 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_findmax(int size, char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		indice;
	int		j;
	char	*temp1;
	char	*temp2;

	i = size;
	indice = size;
	while (*(tab + i))
	{
		temp1 = *(tab + indice);
		temp2 = *(tab + i);
		j = cmp(temp1, temp2);
		if (j > 0)
			indice = i;
		i++;
	}
	return (indice);
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	char	*test;
	int		i;
	int		indice;

	i = 0;
	while (*(tab + i))
	{
		indice = ft_findmax(i, tab, cmp);
		test = *(tab + i);
		*(tab + i) = *(tab + indice);
		*(tab + indice) = test;
		i++;
	}
}
