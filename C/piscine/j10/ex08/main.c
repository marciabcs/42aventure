/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:05:19 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/08 16:55:49 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	**ft_split_whitespaces(char *str);

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *));

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
//	char *str = "bom dia OU 534 sou i?H OU me Eu quem Falo pra voce me Ouvir ouvir  hoje aqui em casa";
	char *str = "c9yJwHCGWqlj YmIwlLZ7n     IZ65QYFXDcS  GRj4fHXBq9   gEeMKp   wEsWu   CcPN2yq60B   FiUbJL9hu618  38  iH   OU  S9l5wAq  ei9Pr58yd  TKVld1S5  ulLso8  3xinKERQ7";
	char **dest;
	int	i;

	i = 0;
	dest = ft_split_whitespaces(str);
	ft_advanced_sort_wordtab(dest, &ft_strcmp);
	while (*(dest + i))
	{
		printf("%s\n", *(dest + i));
		i ++;
	}
	return (0);
}
