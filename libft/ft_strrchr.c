/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:48:02 by nekitoss          #+#    #+#             */
/*   Updated: 2016/11/24 18:48:03 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	size_t i;

	if (c != 0)
	{
		i = ft_strlen(s);
		while (i > 0)
		{
			if (s[i] != c)
				i--;
			else
				return (&s[i]);
		}
		if (s[0] == c)
			return (s);
	}
	else
		return (&s[ft_strlen(s)]);
	return (NULL);
}
