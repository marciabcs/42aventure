/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_ex06.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:11:30 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/08 15:00:24 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_EX06_H
# define DEF_EX06_H

long int		ft_add(long int a, long int b);
long int		ft_sub(long int a, long int b);
long int		ft_mul(long int a, long int b);
long int		ft_div(long int a, long int b);
long int		ft_mod(long int a, long int b);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(long int nb);
long int		ft_atoi(char *str);

# define A ft_atoi(*(argv + 1))
# define B ft_atoi(*(argv + 3))

#endif
