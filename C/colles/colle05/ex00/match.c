/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:49:22 by mcostaes          #+#    #+#             */
/*   Updated: 2016/01/26 16:53:09 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	match(char *s1, char *s2)
{
	if ((!*s1) && (!*s2))
		return (1);
	if ((*s2 == '*') && !*s1)
		return (match(s1, (s2 + 1)));
	if ((*s2 == '*') && *s1)
		return (match(s1, (s2 + 1)) || match((s1 + 1), s2));
	if (*s1 == *s2)
		return (match((s1 + 1), (s2 + 1)));
	else
		return (0);
}