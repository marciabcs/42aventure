/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpham-an <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:10:17 by tpham-an          #+#    #+#             */
/*   Updated: 2016/02/01 15:40:26 by ckramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOP_H
# define FT_DOOP_H

# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_ptfunct
{
	char		ope;
	int			(*ptf)(int, int);
}				t_ptfunc;

int				ft_add(int a, int b);
int				ft_sub(int a, int b);
int				ft_mul(int a, int b);
int				ft_div(int a, int b);
int				ft_mod(int a, int b);

#endif
