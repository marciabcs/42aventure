/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_do_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:10:00 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/08 16:17:47 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def_ex09.h"
#include "ft_opp.h"

void	fonction(char *c, char *d, void (*f)(char*, char*))
{
	f(c, d);
}

void	ft_usage(char *ca, char *cb)
{
	long int a;
	long int b;

	a = ft_atoi(ca);
	b = ft_atoi(cb);
}

void	ft_test(t_opp *ca)
{
	int i;
	
	ft_putstr("error : only [ ");
	i = 0;
	while (*ca[i].opp)
	{
		ft_putstr(ca[i].opp);
		ft_putchar(' ');
		i++;
	}
	ft_putstr("] are accepted.\n");
}

int		main(int argc, char **argv)
{
	t_opp	*tab;
	int		i;
	int		cmp;
	char	*temp;

	i = 0;
	cmp = 0;
	tab = gl_opptab;
	temp = tab->opp;
	if (argc != 4)
		return (0);
	while (*tab[i].opp)
	{
		cmp = ft_strcmp(argv[2], tab[i].opp);
		if (cmp == 0)
		{
			fonction(argv[1], argv[3], tab[i].ftopp);
			return (0);
		}
		i++;
	}
		ft_test(tab);
	return (0);
}
