/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:39:29 by nekitoss          #+#    #+#             */
/*   Updated: 2016/12/02 15:39:30 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**function search first (from end or start)
**occurence of any symbol, except those mentioned in skip string
**both string must be null-terminated. Function does not search for '\0'
**function return position
**to search from end  set parameter from_end=1, otherwise set to zero
**if all string was skipped then function returns -1
**if input is incorrect function returns -2
*/

#include "libft.h"

int		ft_strcstr(const char *big, const char *skip, int from_end)
{
	int		i_b;
	size_t	i_s;

	i_s = 0;
	if (big && skip && *big && *skip)
	{
		i_b = (from_end ? ft_strlen(big) - 1 : 0);
		while (from_end ? i_b >= 0 : big[i_b] != '\0')
		{
			while (big[i_b] != skip[i_s] && skip[i_s] != '\0')
				i_s++;
			if (skip[i_s] == '\0')
				break ;
			i_s = 0;
			i_b = i_b + (from_end ? (-1) : 1);
		}
		return (big[i_b] == '\0' ? -1 : i_b);
	}
	return (-2);
}
