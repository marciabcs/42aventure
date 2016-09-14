/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:38:47 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/06 14:39:53 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>

char				*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*dest;

	dest = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest)
		ft_strcpy(dest, src);
	else
		return ((void*)0);
	return (dest);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par	*par;
	int			i;
	int			size;

	par = (t_stock_par*)malloc((ac + 1) * sizeof(*par));
	if (!par)
		return ((void*)0);
	i = 0;
	while (i < ac)
	{
		size = ft_strlen(av[i]);
		par[i].size_param = size;
		par[i].str = av[i];
		par[i].copy = ft_strdup(av[i]);
		par[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	par[i].str = (void*)0;
	return (par);
}
