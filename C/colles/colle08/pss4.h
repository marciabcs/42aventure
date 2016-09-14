/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pss4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckramer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:00:50 by ckramer           #+#    #+#             */
/*   Updated: 2016/03/02 17:37:17 by ckramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSS4_H
# define PSS4_H

# include <unistd.h>
# include <stdlib.h>
# include <time.h>

typedef struct	s_tab
{
	int		l;
	int		c;
	char	**tab;
}				t_tab;

void			ft_putchar(char c);
void			ft_putnbr(int nb);
int				ft_atoi(char *str);
int				test_vert(int x1, char a, t_tab t, int test);
int				test_hor(int x1, char a, t_tab t, int test);
int				test_diag_l(int x1, char a, t_tab t, int test);
int				test_diag_r(int x1, char a, t_tab t, int test);
int				ft_ai_test_tab(int x, int test, t_tab t);
int				ft_ai_verif_tab(int test, t_tab t);
t_tab			ai_init_tab(t_tab t);
int				ft_ai_play1(t_tab t);
int				is_played(int l, int c, t_tab t);
void			write_line_gride(int c);
void			design_grid(t_tab t);
int				read_number(void);
int				test_play(int p, t_tab t, char init);
int				test_vertical(int x, int y, t_tab t);
int				test_horizontal(int x, int y, t_tab t);
int				test_diag1(int x, int y, t_tab t);
int				test_diag2(int x, int y, t_tab t);
int				test_grid(int p, t_tab t);
int				player(char init, t_tab t);
char			init_sort(void);
void			start_game(t_tab t);
t_tab			init_tab(int l, int c);
int				main(void);

#endif
