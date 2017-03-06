/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:19:43 by nekitoss          #+#    #+#             */
/*   Updated: 2016/12/02 15:19:44 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		end;
	int		start;
	char	*new_str;

	if (s)
	{
		start = ft_strcstr(s, " \n\t", 0);
		end = ft_strcstr(s, " \n\t", 1);
		if (start >= 0 && end >= 0)
		{
			new_str = ft_strnew(end - start + 1);
			if (new_str)
				return (ft_strncpy(new_str, &s[start], end - start + 1));
			return (NULL);
		}
	}
	return (ft_strnew(0));
}
