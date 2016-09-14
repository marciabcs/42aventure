/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:53:49 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/07 14:55:09 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*(s1 + i))
	{
		if (*(s2 + i) != *(s1 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (*(s1 + i) - *(s2 + i));
}

int		ft_findmin(int size, char **tab)
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
		j = ft_strcmp(temp1, temp2);
		if (j >= 0)
			indice = i;
		i++;
	}
	return (indice);
}

void	ft_sort_wordtab(char **tab)
{
	char	*test;
	int		i;
	int		indice;

	i = 0;
	while (*(tab + i))
	{
		indice = ft_findmin(i, tab);
		test = *(tab + i);
		*(tab + i) = *(tab + indice);
		*(tab + indice) = test;
		i++;
	}
}
