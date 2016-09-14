/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:09:29 by mcostaes          #+#    #+#             */
/*   Updated: 2016/02/03 14:23:23 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_list_push_back(t_list **begin_list, void *data);

void	ft_list_push_front(t_list **begin_list, void *data);

int		ft_list_size(t_list *begin_list);

t_list *ft_list_at(t_list *begin_list, unsigned int nbr);

t_list *ft_list_last(t_list *begin_list);

t_list	*ft_list_push_params(int ac, char **av);

void ft_list_reverse(t_list **begin_list);

t_list *ft_create_elem(void *data);

void ft_list_clear(t_list **begin_list);

int	main(int ac, char **av)
{
	t_list		*aux;
	t_list		*aux2;
	t_list		*aux3;
	t_list		*b;
	int			i;
	t_list		**begin;
	int			count;

//	ex00 + ex01 + ex02
	aux = ft_create_elem("create-elem");
	begin = (t_list**)malloc(sizeof(begin));
	begin = &aux;
	ft_list_push_back(&aux,"ps-back1");
	ft_list_push_back(&aux, "ps-back2");
	ft_list_push_back(&aux, "ps-back3");
	ft_list_push_front(&aux, "ps-front");
	ft_list_push_back(&aux, "ps-back4");
	ft_list_push_back(&aux, "ps-back5");
//	ex05
	b = ft_list_push_params(ac, av);
	aux2 = b;
	i = 0;
//	ex03
	count = ft_list_size(b);
	b = aux2;
	printf("\nliste rajoutee par argv ex05\n\n");
	while (aux2)
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
	aux3 = aux;
	count = ft_list_size(aux);
	aux3 = ft_list_last(aux);
	aux = *begin;
	while (aux)//(i < count)
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
	if (aux)
		printf("\nfonction ft_list_at (ex07) begin liste a 3 elem du begin origina = %s\n", (char*)aux->data);
	else
		printf("\nfonction ft_list_at (ex07) begin liste a 3 elem du begin origina = NULL\n");
	count = ft_list_size(aux);
	aux3 = aux;
	i = 0;
	while (aux)
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
	}
	return (0);
}
