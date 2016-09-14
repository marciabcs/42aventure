/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:39:58 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/06 14:41:22 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H

# include <unistd.h>

typedef struct	s_stock_par
{
	int		size_param;
	char	*str;
	char	*copy;
	char	**tab;
}				t_stock_par;

void			ft_putchar(char	c);
char			**ft_split_whitespaces(char *str);
int				lines_matrix(char *str);
int				taille(char *str, int ind);
void			ft_show_tab(struct s_stock_par *par);
t_stock_par		*ft_param_to_tab(int ac, char **av);

#endif
