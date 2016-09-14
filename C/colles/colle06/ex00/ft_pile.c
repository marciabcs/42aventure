/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:47:32 by mouaret           #+#    #+#             */
/*   Updated: 2016/02/02 17:46:56 by ckramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_pile.h"
#include "ft_utils.h"

t_pile	*create_elem_pile(void)
{
	t_pile *elem;

	elem = malloc(sizeof(t_pile));
	elem->item = 0;
	elem->type = TYPE_UNKNOWN;
	elem->next = elem;
	elem->prev = elem;
	return (elem);
}

int		pile_push_elem(t_pile **pile, char ope, int val)
{
	t_pile	*pile_elem;
	t_pile	*pile_head;

	pile_elem = create_elem_pile();
	pile_elem->type = ope;
	pile_elem->item = val;
	pile_head = *pile;
	if (pile_head)
	{
		pile_elem->next = pile_head;
		pile_elem->prev = pile_head->prev;
		pile_head->prev = pile_elem;
		pile_head = pile_elem->prev;
		pile_head->next = pile_elem;
	}
	*pile = pile_elem;
	return (1);
}

int		pile_push_operand(t_pile **pile, int val)
{
	if (pile_push_elem(pile, TYPE_OPERAND, val))
		return (1);
	return (0);
}

int		pile_push_operator(t_pile **pile, char ope)
{
	if (pile_push_elem(pile, TYPE_OPERATOR, ope))
		return (1);
	return (0);
}

char	pile_pop_front(t_pile **pile, int *item)
{
	t_pile	*pile_head;
	t_pile	*p1;
	char	type;

	pile_head = *pile;
	if (pile_head)
	{
		*item = pile_head->item;
		type = pile_head->type;
		if (pile_head->next == pile_head)
			*pile = 0;
		else
		{
			p1 = pile_head->next;
			p1->prev = pile_head->prev;
			p1 = pile_head->prev;
			p1->next = pile_head->next;
			*pile = p1->next;
		}
		free(pile_head);
		return (type);
	}
	return (TYPE_UNKNOWN);
}
