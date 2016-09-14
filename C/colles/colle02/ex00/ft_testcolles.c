/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testcolles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:41:37 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/08 16:34:17 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);

void	affichage(int err, int x, int y);

int		ft_putligne(char *table, char *c, int n, int i);

int		tc00(int x, int y, char *a)
{
	int		j;
	char	*temp;
	char	*chars00a;
	char	*chars00b;
	char	*chars00c;

	chars00a = "o-o";
	chars00b = "o-o";
	chars00c = "| |";
	temp = chars00c;
	j = 2;
	if (ft_putligne(a, chars00a, x, 0) == 1)
		return (1);
	while (j <= (y - 1))
	{
		if (j == y)
			temp = chars00b;
		if (ft_putligne(a, temp, x, ((x + 1) * (j - 1))) == 1)
			return (1);
		j++;
	}
	ft_putstr("[colle00] ");
	affichage(1, x, y);
	return (0);
}

int		tc01(int x, int y, char *a)
{
	int		j;
	char	*temp;
	char	*chars01a;
	char	*chars01b;
	char	*chars01c;

	chars01a = "/*\\";
	chars01b = "\\*/";
	chars01c = "* *";
	temp = chars01c;
	j = 2;
	if (ft_putligne(a, chars01a, x, 0) == 1)
		return (1);
	while (j <= y)
	{
		if (j == y)
			temp = chars01b;
		if (ft_putligne(a, temp, x, ((x + 1) * (j - 1))) == 1)
			return (1);
		j++;
	}
	ft_putstr("[colle01] ");
	affichage(1, x, y);
	return (0);
}

int		tc02(int x, int y, char *a)
{
	int		j;
	char	*temp;
	char	*chars02a;
	char	*chars02b;
	char	*chars02c;

	chars02a = "ABA";
	chars02b = "CBC";
	chars02c = "B B";
	temp = chars02c;
	if (ft_putligne(a, chars02a, x, 0) == 1)
		return (1);
	j = 2;
	while (j <= y)
	{
		if (j == y)
			temp = chars02b;
		if (ft_putligne(a, temp, x, ((x + 1) * (j - 1))) == 1)
			return (1);
		j++;
	}
	ft_putstr("[colle02] ");
	affichage(1, x, y);
	return (0);
}

int		tc03(int x, int y, char *a)
{
	int		j;
	char	*temp;
	char	*chars03a;
	char	*chars03b;
	char	*chars03c;

	chars03a = "ABC";
	chars03b = "ABC";
	chars03c = "B B";
	temp = chars03c;
	if (ft_putligne(a, chars03a, x, 0) == 1)
		return (1);
	j = 2;
	while (j <= y)
	{
		if (j == y)
			temp = chars03b;
		if (ft_putligne(a, temp, x, ((x + 1) * (j - 1))) == 1)
			return (1);
		j++;
	}
	ft_putstr("[colle03] ");
	affichage(1, x, y);
	return (0);
}

int		tc04(int x, int y, char *a)
{
	int		j;
	char	*temp;
	char	*chars04a;
	char	*chars04b;
	char	*chars04c;

	chars04a = "ABC";
	chars04b = "CBA";
	chars04c = "B B";
	temp = chars04c;
	if (ft_putligne(a, chars04a, x, 0) == 1)
		return (1);
	j = 2;
	while (j <= y)
	{
		if (j == y)
			temp = chars04b;
		if (ft_putligne(a, temp, x, ((x + 1) * (j - 1))) == 1)
			return (1);
		j++;
	}
	ft_putstr("[colle04] ");
	affichage(1, x, y);
	return (0);
}
