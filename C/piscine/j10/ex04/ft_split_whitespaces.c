/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 12:19:13 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/05 14:29:27 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define A *(str + k)

int		lines_matrix(char *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (*(str + k))
	{
		if (A == 9 || A == 32 || A == '\n')
			k++;
		else
		{
			k++;
			if (A == 9 || A == 32 || A == '\n' || !(A))
				i++;
		}
	}
	return (i);
}

int		taille(char *str, int ind)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	while (*(str + k))
	{
		k++;
		j++;
		if (A == 9 || A == 32 || A == '\n' || !(A))
		{
			if (i == ind)
				return (j);
			else
				j = 0;
			i++;
		}
	}
	return (0);
}

void	write_vector(char *str, char **dest)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (*(str + k))
	{
		if (A == 9 || A == 32 || A == '\n')
			k++;
		else
		{
			*(*(dest + i) + j) = *(str + k);
			k++;
			j++;
			if (A == 9 || A == 32 || A == '\n' || !(A))
			{
				*(*(dest + i) + j) = 0;
				i++;
				j = 0;
			}
		}
	}
	*(dest + i) = 0;
}

char	**ft_split_whitespaces(char *string)
{
	char	**dest;
	char	*str;
	int		line;
	int		i;
	int		n;

	str = string;
	line = lines_matrix(str);
	dest = (char**)malloc((line + 1) * (sizeof(*dest)));
	i = 0;
	while (i < line)
	{
		n = taille(str, i);
		*(dest + i) = (char*)malloc((n + 1) * (sizeof(dest)));
		i++;
	}
	write_vector(str, dest);
	return (dest);
}
