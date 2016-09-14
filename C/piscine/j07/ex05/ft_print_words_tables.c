/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:30:03 by mcostaes          #+#    #+#             */
/*   Updated: 2016/02/04 12:04:30 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *string)
{
	char *str;

	str = string;
	while (*str)
		ft_putchar(*(str++));
	ft_putchar('\n');
}

void	ft_print_words_tables(char **tab)
{
	while (*(tab))
		ft_putstr(*(tab++));
}
