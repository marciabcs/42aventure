/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:26:46 by mcostaes          #+#    #+#             */
/*   Updated: 2016/02/03 11:07:37 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_aux(t_list **begin_list, t_list *aux, t_list *temp)
{
	if (aux == *begin_list)
	{
		*begin_list = aux->next;
		temp = aux->next;
	}
	else
		temp->next = aux->next;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*erase;
	t_list	*aux;
	t_list	*temp;

	aux = *begin_list;
	temp = *begin_list;
	while (aux)
	{
		if (cmp(aux->data, data_ref) == 0)
		{
			erase = aux;
			ft_aux(begin_list, aux, temp);
			aux = aux->next;
			free(erase);
		}
		else
		{
			temp = aux;
			aux = aux->next;
		}
	}
}
