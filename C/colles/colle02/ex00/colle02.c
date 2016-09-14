/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:25:00 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/08 13:57:46 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putligne(char c1, char c2, char c3, int n)
{
	int		i;
	char	a;

	i = 0;
	a = '\n';
	write(1, &c1, 1);
	if (n > 1)
	{
		while (i < n - 2)
		{
			write(1, &c2, 1);
			i = i + 1;
		}
		write(1, &c3, 1);
	}
	write(1, &a, 1);
	return (0);
}

int		ft_char_to_int(char *str)
{
	int i;
	int number;

	i = 0;
	number = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0') && (str[i] <= '9')))
			return (-1);
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number);
}

int		colle(int x, int y)
{
	int j;

	j = 0;
	while (j < y)
	{
		if (j == 0)
			ft_putligne('A', 'B', 'A', x);
		else if (j == y - 1)
			ft_putligne('C', 'B', 'C', x);
		else
			ft_putligne('B', ' ', 'B', x);
		j = j + 1;
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int x;
	int y;

	if (argc != 3)
		return (0);
	if (!((argv[1][0] >= '0') && (argv[1][0] <= '9')))
		return (0);
	else if (!((argv[2][0] >= '0') && (argv[2][0] <= '9')))
		return (0);
	else
	{
		x = ft_char_to_int(argv[1]);
		y = ft_char_to_int(argv[2]);
		if (x == -1 || y == -1)
			return (0);
		colle(x, y);
	}
	return (0);
}
