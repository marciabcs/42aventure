/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 11:53:02 by mcostaes          #+#    #+#             */
/*   Updated: 2016/03/15 11:23:17 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void	ft_putstr_err(char *str)
{
	while (*str)
	{
		write(2, str++, 1);
	}
}

void	ft_write_av(int ac, char **av)
{
	int		i;
	int		fd;
	char	c;

	i = 1;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_err("cat: ");
			ft_putstr_err(av[i]);
			if (errno == 2)
				ft_putstr_err(": No such file or directory\n");
			else if (errno == 13)
				ft_putstr_err(": Permission denied\n");
		}
		else
			while (read(fd, &c, 1))
				write(1, &c, 1);
		close(fd);
		i++;
	}
}

void	ft_read_std_in(void)
{
	char c;

	while (read(0, &c, 1))
		write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_read_std_in();
	else
		ft_write_av(argc, argv);
	return (0);
}
