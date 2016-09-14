/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ho.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:03:41 by mouaret           #+#    #+#             */
/*   Updated: 2016/02/02 14:48:52 by mouaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"
#include "ft_utils.h"
#include <stdlib.h>

int		ft_is_operator(char c)
{
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '%'))
		return (1);
	else
		return (0);
}

void	ft_print_pile_elem(t_pile *elem)
{
	if (elem)
	{
		ft_putchar(' ');
		if (elem->type == TYPE_OPERAND)
			ft_putnbr(elem->item);
		else
			ft_putchar((char)elem->item);
		ft_putchar(' ');
	}
}

void	print_pile_front(t_pile *pile)
{
	t_pile	*p1;
	t_pile	*p0;

	ft_putstr("\n-------------print_pile_front-------------\n");
	p1 = pile;
	p0 = p1;
	while (p1)
	{
		ft_print_pile_elem(p1);
		p1 = p1->next;
		if (p1 == p0)
			return ;
	}
}

void	print_pile_back(t_pile *pile)
{
	t_pile	*p1;
	t_pile	*p0;

	ft_putstr("\n-------------print_pile_back-------------\n");
	p1 = pile;
	if (p1)
		p1 = p1->prev;
	p0 = p1;
	while (p1)
	{
		ft_print_pile_elem(p1);
		p1 = p1->prev;
		if (p1 == p0)
			return ;
	}
}

int		pile_pop_front_next(t_pile **pile, int *item)
{
	int type;

	ft_putstr("Pop front : ");
	type = pile_pop_front(pile, item);
	if (type == TYPE_OPERATOR)
	{
		ft_putstr("OPERATOR ");
		ft_putchar(*item);
	}
	else
	{
		ft_putstr("OPERAND  ");
		ft_putnbr(*item);
	}
	ft_putchar('\n');
	return (type);
}

int	main(int argc, char **argv)
{
	int		i;
	int 	c;
	t_pile	*pile;
	int		item;

	pile = 0;
	i = 1;
	while (i < argc)
	{
		c = argv[i][0];
		ft_putchar(c); ft_putchar(' ');
		if (ft_is_operator(c))
			pile_push_operator(&pile, (char)c);
		else
			pile_push_operand(&pile, atoi(argv[i]));
		i++;
	}

	print_pile_front(pile);
	ft_putchar('\n');

	pile_pop_front_next(&pile, &item);
	pile_pop_front_next(&pile, &item);
	pile_pop_front_next(&pile, &item);

	print_pile_front(pile);

	print_pile_back(pile);
	ft_putstr("\n-----------------------------------------\n");
	return (0);
}
