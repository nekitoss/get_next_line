/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:56:14 by nekitoss          #+#    #+#             */
/*   Updated: 2016/11/24 18:56:15 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *s2)
{
	size_t	b;
	size_t	l;
	size_t	max_len;

	if (s2[0] != '\0' && s2 != NULL)
	{
		max_len = ft_strlen(big) - ft_strlen(s2);
		b = 0;
		while (big[b] != '\0' && b <= max_len)
		{
			l = 0;
			while (big[b] != '\0' && s2[l] != '\0' && big[b + l] == s2[l])
				l++;
			if (s2[l] == '\0')
				return ((char *)(&big[b]));
			b++;
		}
		return (NULL);
	}
	return ((char *)(big));
}
