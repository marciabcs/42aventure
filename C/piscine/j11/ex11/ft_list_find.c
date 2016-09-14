/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:29:36 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/22 11:35:26 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*aux;
	t_list	*find;

	aux = begin_list;
	while (aux)
	{
		if (cmp(aux->data, data_ref) == 0)
			return (aux);
		aux = aux->next;
	}
	find = aux;
	return (find);
}
