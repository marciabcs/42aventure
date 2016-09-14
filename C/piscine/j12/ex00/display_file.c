/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 11:52:32 by mcostaes          #+#    #+#             */
/*   Updated: 2016/02/12 09:22:14 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	c;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (1);
		while (read(fd, &c, 1))
			write(1, &c, 1);
		close(fd);
		return (0);
	}
	else
	{
		if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		else
			write(2, "File name missing.\n", 19);
		return (1);
	}
}
