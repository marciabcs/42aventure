/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:23:02 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/21 12:40:02 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void*),
		void *data_ref, int (*cmp)())
{
	t_list	*aux;

	aux = begin_list;
	while (aux)
	{
		if (cmp(aux->data, data_ref) == 0)
			f(aux->data);
		aux = aux->next;
	}
}
