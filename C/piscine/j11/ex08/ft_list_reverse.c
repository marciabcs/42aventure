/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 11:48:11 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/22 11:49:10 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*av;
	t_list	*aux;
	t_list	*begin;

	begin = *begin_list;
	aux = begin;
	if (aux && aux->next)
	{
		while (aux->next)
			aux = aux->next;
		*begin_list = aux;
		while (begin->next)
		{
			av = begin;
			aux = av->next;
			while (aux->next)
			{
				aux = aux->next;
				av = av->next;
			}
			aux->next = av;
			av->next = NULL;
		}
	}
}
