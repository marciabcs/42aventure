/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translator_expr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:40:43 by mcostaes          #+#    #+#             */
/*   Updated: 2016/02/02 23:34:05 by mouaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"
#include "ft_utils.h"
#include <unistd.h>

int			p(char a, char b)
{
	int i;
	int j;

	if (a == '*' || a == '/' || a == '%')
		i = 2;
	else if (a == '+' || a == '-')
		i = 1;
	else
		i = 0;
	if (b == '(')
		j = 3;
	else if (b == '*' || b == '/' || b == '%')
		j = 2;
	else if (b == '+' || b == '-')
		j = 1;
	else
		j = 0;
	if (i > j)
		return (1);
	else
		return (0);
}

char		*advance_str(char *input_stream, t_pile **pile)
{
	char sign;
	char *s;

	s = input_stream;
	sign = (*s == '-') || (*s == '+');
	pile_push_operand(pile, ft_atoi(s));
	if (sign)
		s++;
	while (*s && *s >= '0' && *s <= '9')
		s++;
	s--;
	return (s);
}

char		*my_init(t_pile **stack, t_pile **pile, char *str)
{
	*pile = NULL;
	*stack = NULL;
	return (str - 1);
}

t_pile		*blah(t_pile **stack, t_pile **pile)
{
	while (*stack)
		pile_push_operator(pile, ft_stack_pop_operator(stack));
	return (*pile);
}

t_pile		*ft_trans_expr(char *s)
{
	t_pile	*pile;
	t_pile	*k;

	s = my_init(&k, &pile, s);
	while (*++s)
		if ((((*s == '-') || (*s == '+')) && is_dig(*(s + 1))) || is_dig(*s))
			s = advance_str(s, &pile);
		else if (*s == '(')
			ft_stack_push_operator(&k, (int)*s);
		else if (is_operator(*s))
			if ((!k) || (k && p(*s, (char)k->item)))
				ft_stack_push_operator(&k, (int)*s);
			else
			{
				while (k && !p(*s, (char)k->item) && (char)k->item != '(')
					pile_push_operator(&pile, ft_stack_pop_operator(&k));
				ft_stack_push_operator(&k, (int)*s);
			}
		else if (*s == ')')
		{
			while (k && (char)k->item != '(')
				pile_push_operator(&pile, ft_stack_pop_operator(&k));
			ft_stack_pop_operator(&k);
		}
	return (blah(&k, &pile));
}
