/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:37:39 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/12 15:56:10 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	while (*(str))
		ft_putchar(*(str++));
}

void	ft_putnbr(int taille)
{
	int n;
	int fac;
	int i;

	n = taille;
	fac = 1;
	i = 0;
	while (n >= 10)
	{
		fac *= 10;
		n /= 10;
		i++;
	}
	n = taille;
	i = 0;
	while (fac > 0)
	{
		ft_putchar((n / fac) + '0');
		n %= fac;
		fac /= 10;
		i++;
	}
}

void	ft_print_words_tables(char **tab)
{
	while (*tab)
	{
		ft_putstr(*tab);
		tab++;
		ft_putchar('\n');
	}
}

void	ft_show_tab(t_stock_par *par)
{
	int			i;
	t_stock_par *p;

	p = par;
	i = 0;
	while (p[i].str)
	{
		ft_putstr(p[i].str);
		ft_putchar('\n');
		ft_putnbr(p[i].size_param);
		ft_putchar('\n');
		ft_print_words_tables(p[i].tab);
		i++;
	}
}
