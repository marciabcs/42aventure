/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:08:14 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/08 14:37:01 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_sort(int *tab, int length, int(*f)(int, int));

int	su(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	int tab[] = {0, 2, 3, 4, 5, 8, 9};
	int tab2[] = {0, 2, 1, 4, 5, 8, 9};
	int tab3[] = {0, 0, 2, 4, 5, 5, 9};
	int tab4[] = {0, 0, 2, 4, 5, 5, 4};
	int tab5[] = {6, 6, 5, 4, 3, 2, 1};

	printf(" tab = {0, 2, 3, 4, 5, 8, 9}\n");
	printf("Is sort? %d\n", ft_is_sort(tab, 7, &su));
	printf(" tab = {0, 2, 1, 4, 5, 8, 9}\n");
	printf("Is sort? %d\n", ft_is_sort(tab2, 7, &su));
	printf(" tab = {0, 0, 2, 4, 5, 5, 9}\n");
	printf("Is sort? %d\n", ft_is_sort(tab3, 7, &su));
	printf(" tab = {0, 0, 2, 4, 5, 5, 4}\n");
	printf("Is sort? %d\n", ft_is_sort(tab4, 7, &su));
	printf(" tab = {6, 6, 5, 4, 3, 2, 1}\n");
	printf("Is sort? %d\n", ft_is_sort(tab5, 7, &su));
	return (0);
}
