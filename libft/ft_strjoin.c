/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:58:24 by nekitoss          #+#    #+#             */
/*   Updated: 2016/12/01 21:58:24 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (new_str)
		{
			while (*s1)
				new_str[i++] = *s1++;
			while (*s2)
				new_str[i++] = *s2++;
			return (new_str);
		}
	}
	return (NULL);
}
