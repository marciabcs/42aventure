/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 11:20:59 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/06 09:30:23 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		size_argv(int argc, char **argv)
{
	int i;
	int j;
	int k;

	i = 1;
	j = 0;
	k = 0;
	while (i < argc)
	{
		while (*(*(argv + i) + j))
		{
			j++;
			k++;
		}
		i++;
		j = 0;
		k++;
	}
	return (k);
}

void	write_vector(int argc, char **argv, char *dest)
{
	int i;
	int j;
	int k;

	i = 1;
	j = 0;
	k = 0;
	while (i < argc)
	{
		while (*(*(argv + i) + j))
		{
			*(dest + k) = (*(*(argv + i) + j));
			k++;
			j++;
		}
		i++;
		if (i != argc)
			*(dest + k) = '\n';
		else
			*(dest + k) = '\0';
		j = 0;
		k++;
	}
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*dest;
	int		n;

	n = size_argv(argc, argv);
	dest = (char*)malloc((n + 1) * (sizeof(dest)));
	write_vector(argc, argv, dest);
	return (dest);
}
