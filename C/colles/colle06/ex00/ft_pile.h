/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckramer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:01:16 by ckramer           #+#    #+#             */
/*   Updated: 2016/02/02 23:14:27 by mouaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PILE_H
# define FT_PILE_H

# define TYPE_UNKNOWN	0
# define TYPE_OPERAND	1
# define TYPE_OPERATOR	2

typedef struct		s_pile
{
	int				item;
	char			type;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

t_pile				*ft_trans_expr(char *str);
int					pile_push_operator(t_pile **pile, char ope);
int					pile_push_operand(t_pile **pile, int val);
char				pile_pop_front(t_pile **pile, int *item);
int					pile_pop_operand(t_pile **pile);
int					pile_pop_operator(t_pile **pile);
int					pile_get_next(t_pile **pile, int *value, int *type);
int					ft_stack_pop_operand(t_pile **begin);
int					ft_stack_pop_operator(t_pile **begin);
void				ft_stack_push_operand(t_pile **begin, int val);
void				ft_stack_push_operator(t_pile **begin, int ope);
int					ft_doop(char ope, int a, int b);
int					eval_expr(char *str);
void				ft_pile_push(t_pile **begin, int val, char ope);
int					is_operator(char c);

#endif
