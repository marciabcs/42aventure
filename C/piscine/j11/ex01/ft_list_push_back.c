/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:07:27 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/12 16:08:27 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*aux;

	aux = *begin_list;
	if (!aux)
		*begin_list = ft_create_elem(data);
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = ft_create_elem(data);
	}
}
