/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_ex09.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:10:41 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/08 16:14:38 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_EX09_H
# define DEF_EX09_H

void			ft_add(char *ca, char *cb);
void			ft_sub(char *ca, char *cb);
void			ft_mul(char *ca, char *cb);
void			ft_div(char *ca, char *cb);
void			ft_mod(char *ca, char *cb);
void			ft_usage(char *ca, char *cb);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(long int nb);
long int		ft_atoi(char *str);
long int		ft_strcmp(char *s1, char *s2);

typedef struct	s_opp
{
	char *opp;
	void (*ftopp)(char *, char *);
}				t_opp;

#endif
