/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:20:56 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/07 11:09:03 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_str_is_lowercase(char *str);
int		ft_any(char **tab, int (*f)(char*));
char	**ft_split_whitespaces(char *str);

int		main(void)
{
	char			*str = "aaaaaa bbbbbb ccccc ddddddd";
	char			*str1 = "aaaaaa bbbbbb ccCCccc ddddddd";
	int 			i;

	printf("str = %s\n", str);
	i = ft_any(ft_split_whitespaces(str), &ft_str_is_lowercase);
	printf("fonction ft_any = %d\n", i);
	printf("str = %s\n", str1);
	i = ft_any(ft_split_whitespaces(str1), &ft_str_is_lowercase);
	printf("fonction ft_any = %d\n", i);
	return (0);
}
