/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:18:15 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/08 17:09:48 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		tc00(int x, int y, char *a);

int		tc01(int x, int y, char *a);

int		tc02(int x, int y, char *a);

int		tc03(int x, int y, char *a);

int		tc04(int x, int y, char *a);

int		ft_putchar(char c);

void	ft_putstr(char *str);

void	ft_putnbr(int nb);

void	affichage(int err, int x, int y)
{
	char	*msg;
	char	*msg2;

	msg = "aucune\n";
	msg2 = " || ";
	if (err == 0)
		ft_putstr(msg);
	else if (err == 1)
	{
		ft_putnbr(x);
		ft_putchar(' ');
		ft_putnbr(y);
	}
	else if (err == 2)
		ft_putstr(msg2);
}

void	ft_tests(int x, int y, char *a)
{
	int		(*test[5])(int x, int y, char *a);
	int		err;
	int		i;
	int		j;

	test[0] = &tc00;
	test[1] = &tc01;
	test[2] = &tc02;
	test[3] = &tc03;
	test[4] = &tc04;
	i = 0;
	j = 0;
	err = 1;
	while (i < 5)
	{
		err = test[i](x, y, a);
		if (err == 1)
			j++;
		i++;
	}
	if (j == 5)
		affichage(0, x, y);
}

int		main(void)
{
	char	*str;
	char	*a;
	int		i;
	int		x;
	int		y;

	str = malloc(sizeof(*str) + 1);
	a = str;
	y = 0;
	x = 0;
	read(0, str, 1000);
	free(str);
	i = 0;
	while (a[x] != '\n')
		x++;
	while (a[i] != '\0')
	{
		if (a[i] == '\n')
			y++;
		i++;
	}
	ft_tests(x, y, a);
	ft_putchar('\n');
	return (0);
}
