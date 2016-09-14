/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:47:57 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/16 09:55:15 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "ft_tail.h"

int		test_av1(char **v)
{
	if (v[1][0] == '-' && v[1][1] == 'c')
	{
		if (!v[1][2] && !v[2])
			return (0);
		if (!v[1][2] && (v[2][0] == '+' ||
					v[2][0] == '-' || (v[2][0] >= '0' && v[2][0] <= '9')))
			return (3);
		if (v[1][2] == '+' ||
					v[1][2] == '-' || (v[1][2] >= '0' && v[1][2] <= '9'))
			return (2);
	}
	return (0);
}

void	write_names(int n, int i, int ac, char **av)
{
	int j;
	int k;

	k = test_av1(av);
	if (i <= ac && k != (ac - 1))
	{
		if (n == 1)
			write(1, "==> ", 4);
		else
			write(1, "\n==> ", 5);
		j = 0;
		while (av[i][j])
			write(1, &av[i][j++], 1);
		write(1, " <==\n", 5);
	}
}

int		size_file(char *file_name)
{
	int		i;
	int		fd;
	char	c;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd >= 0)
		while (read(fd, &c, 1))
			i++;
	else
	{
		write(2, "tail: ", 6);
		while (*file_name)
			write(2, file_name++, 1);
		if (errno == 2)
			write(2, ": No such file or directory\n", 28);
		if (errno == 13)
			write(2, ": Permission denied\n", 20);
	}
	close(fd);
	return (i);
}

void	ft_write(int i, char *str, char **av, int size)
{
	int j;
	int a;

	j = open(av[i], O_RDONLY);
	read(j, str, size);
	close(j);
	str[size] = '\0';
	if (test_av1(av) == 2)
	{
		a = (ft_atoi(av[1] + 2) > 0) ? ft_atoi(av[1] + 2) : -ft_atoi(av[1] + 2);
		if (av[1][2] == '+')
			j = a - 1;
		else
			j = (size - a) < 0 ? 0 : size - a;
	}
	else
	{
		a = (ft_atoi(av[2]) > 0) ? ft_atoi(av[2]) : -ft_atoi(av[2]);
		if (av[2][0] == '+')
			j = a - 1;
		else
			j = (size - a) < 0 ? 0 : size - a;
	}
	while (str[j])
		write(1, &str[j++], 1);
}

int		main(int ac, char **av)
{
	int		i;
	int		n;
	int		size;
	char	*str;

	n = 0;
	i = (ac > 1) ? test_av1(av) : 0;
	if (i == 0 || i >= ac)
	{
		ft_read_std_in(ac, i);
		return (0);
	}
	while (i < ac)
	{
		size = size_file(av[i]);
		if (size > 0)
		{
			str = (char*)malloc((size + 1) * (sizeof(char)));
			write_names(++n, i, ac, av);
			ft_write(i, str, av, size);
			free(str);
		}
		i++;
	}
	return (0);
}
