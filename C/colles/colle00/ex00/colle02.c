/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:32:29 by mcostaes          #+#    #+#             */
/*   Updated: 2015/11/24 14:22:01 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_putchar(char c);

/*
** This function reads the three characters of the line and the line width
** It writes the first character
** Then (n-2) times the middle character
** Ends with writing the last character and return line
*/

int	ft_putline(char c1, char c2, char c3, int n)
{
	int		i;

	i = 0;
	ft_putchar(c1);
	if (n > 1)
	{
		while (i < n - 2)
		{
			ft_putchar(c2);
			i = i + 1;
		}
		ft_putchar(c3);
	}
	ft_putchar('\n');
	return (0);
}

/*
** Loop to access the appropriate characters per line
** The first condition writes first line
** The second condition writes the last line
** The third condition writes intermediate lines
*/

int	colle(int x, int y)
{
	int j;

	j = 0;
	while (j < y)
	{
		if (j == 0)
			ft_putline('A', 'B', 'A', x);
		else if (j == y - 1)
			ft_putline('C', 'B', 'C', x);
		else
			ft_putline('B', ' ', 'B', x);
		j = j + 1;
	}
	return (0);
}
