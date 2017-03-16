/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:06:05 by nekitoss          #+#    #+#             */
/*   Updated: 2016/11/24 18:06:05 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (s)
	{
		if (c != 0)
		{
			while (s[i] != '\0')
			{
				if (s[i] != c)
					i++;
				else
					return ((char *)&s[i]);
			}
		}
		else
			return ((char *)&s[ft_strlen(s)]);
	}
	return (NULL);
}
