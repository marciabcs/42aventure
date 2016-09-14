/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:36:34 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/22 10:20:58 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*aux;

	aux = *begin_list1;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
		aux->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}
