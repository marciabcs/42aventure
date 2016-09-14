/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:45:55 by mcostaes          #+#    #+#             */
/*   Updated: 2015/12/03 10:28:51 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str);

int		main(void)
{
	char chaine[] = "Hello World!!!!!!!";
	char *ptr;

	ptr = chaine;
	ft_putstr(ptr);
	ft_putchar('\n');
	return (0);
}
