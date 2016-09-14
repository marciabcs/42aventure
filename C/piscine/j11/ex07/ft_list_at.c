/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:16:18 by mcostaes          #+#    #+#             */
/*   Updated: 2016/02/03 12:51:49 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*aux;

	i = 0;
	aux = begin_list;
	while (i < nbr)
	{
		if (!aux)
			return (NULL);
		aux = aux->next;
		i++;
	}
	return (aux);
}
