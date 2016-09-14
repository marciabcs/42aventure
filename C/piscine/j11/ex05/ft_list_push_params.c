/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:29:59 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/22 11:49:57 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*aux;
	t_list	*first;
	int		i;

	i = 1;
	if (ac <= 0)
		return (NULL);
	if (av[0])
		aux = ft_create_elem(av[0]);
	else
		aux = NULL;
	first = aux;
	while ((i < ac) && av[i])
	{
		aux = ft_create_elem(av[i]);
		aux->next = first;
		first = aux;
		i++;
	}
	return (first);
}
