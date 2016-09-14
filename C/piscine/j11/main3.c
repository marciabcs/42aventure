/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:21:25 by mcostaes          #+#    #+#             */
/*   Updated: 2016/02/03 14:20:08 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar(' ');
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*(s1 + i))
	{
		if (*(s2 + i) != *(s1 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	if (*(s2 + i))
		return (*(s1 + i) - *(s2 + i));
	return (0);
}

t_list *ft_create_elem(void *data);

void	ft_list_push_back(t_list **begin_list, void *data);

void	ft_list_push_front(t_list **begin_list, void *data);

void ft_list_foreach(t_list *begin_list, void (*f)(void *));

t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());

void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());

t_list	*ft_list_push_params(int ac, char **av);

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

void ft_list_merge(t_list **begin_list1, t_list *begin_list2);

int	main(int ac, char **av)
{
	t_list		*aux = NULL;
	t_list		*aux2;
	//	t_list		*aux3;
	t_list		*b;
	//	int			i;
	t_list		*begin;
	//	int			count;

	b = ft_list_push_params(ac, av);
	aux2 = b;
	printf("\nimprime avec ft_putstr avec ex09 ft_list_foreach\n     ");
	ft_list_foreach(b, (void (*)(void*))&ft_putstr);
	printf("\n\nTrouve le mot BONJOUR par le ex10 ft_list_foreach_if\n     ");
	ft_list_foreach_if(b, (void (*)(void *))&ft_putstr, "bonjour", &ft_strcmp);
	aux = ft_list_find(b, "bonjour", &ft_strcmp);
	printf("\n");
	printf("\ntrouve le pointeur avec le mot BONJOUR par la fonction find_list ex11\n");
	if (aux)
		printf("  %s\n", (char*)aux->data);
	printf("\n");
	ft_list_remove_if(&b, "bonjour", &ft_strcmp);
	printf("imprime la liste apres avoir efacce les mots BONJOUR ex12\n");
	ft_list_foreach(b, (void (*)(void*))&ft_putstr);
	printf("\n");
	begin = ft_create_elem("cre_elem");
	ft_list_push_back(&begin,"ps-back1");
	ft_list_push_front(&begin, "ps-front1");
	ft_list_push_back(&begin, "ps-back2");
	ft_list_push_back(&begin, "ps-back3");
	ft_list_push_front(&begin, "ps-front2");
	ft_list_push_back(&begin, "ps-back4");
	ft_list_push_back(&begin, "ps-back5");
	ft_list_push_front(&begin, "ps-front3");
	ft_list_merge(&b, begin);
	printf("\nimprime la nouvelle liste apres passer la fonction MERGE ex13 avec une autre liste\n");
	ft_list_foreach(b, (void (*)(void*))&ft_putstr);
	/*	i = 0;
	//	ex03
	count = ft_list_size(b);
	printf("\nliste rajoutee par argv ex05\n\n");
	while (i < count)
	{
	printf("%s\n", (char*)aux2->data);
	aux2 = aux2->next;
	i++;
	}
	printf("size ex03  (par argv) = %d\n", count);
	//	ex04
	aux3 = ft_list_last(b);
	printf("last ex04 (par argv) = %s\n", (char*)aux3->data);
	printf("\nliste rajoutee par fonctions pushback et push front ex00 a ex02\n\n");
	i = 0;
	count = ft_list_size(aux);
	aux3 = ft_list_last(aux);
	while (i < count)
	{
	printf("%s\n", (char*)aux->data);
	aux = aux->next;
	i++;
	}
	printf("size ex03  (par push back and front)= %d\n", count);
	printf("last ex04  (par push back and front) = %s\n", (char*)aux3->data);
	//	ex06
	ft_list_clear(begin);
	aux = *begin;
	count = ft_list_size(aux);
	printf("\nsize after erase liste ex06  (par push back and front) = %d\n", count);
	//	ex07	
	aux = ft_list_at(b, 3);
	printf("\nfonction ft_list_at (ex07) begin liste a 3 elem du begin origina = %s\n", (char*)aux->data);
	count = ft_list_size(aux);
	aux3 = aux;
	i = 0;
	while (i < count)
	{
	printf("%s\n", (char*)aux->data);
	aux = aux->next;
	i++;
	}
	printf("new size (ex03) = %d\n", count);
	begin = &b;
	//	ex08
	ft_list_reverse(begin);
	aux = *begin;
	printf("\nFonction reverse (ex08) on va retrouver la phrase ecrite en argv\n");
	while (aux)
	{
	printf("%s\n", (char*)aux->data);
	aux = aux->next;
	}*/
	//printf("after clear : last = %s\n", (char*)aux->data);
	return (0);
}
