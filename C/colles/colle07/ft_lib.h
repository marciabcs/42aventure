/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:47:31 by mdaoui            #+#    #+#             */
/*   Updated: 2016/02/16 17:53:51 by mdaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB
# define FT_LIB

# include <unistd.h>
# include <stdlib.h>

unsigned int	ft_hash(char *key, int size);
int				ft_strcmp(char *s1, char *s2);

#endif
