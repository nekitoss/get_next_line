/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:34:46 by nekitoss          #+#    #+#             */
/*   Updated: 2016/12/01 21:34:46 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	char	tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s && f)
	{
		new_str = ft_strnew(ft_strlen(s));
		if (new_str)
			while (*s)
			{
				tmp = f(j++, *s++);
				if (tmp)
					new_str[i++] = tmp;
			}
		return (new_str);
	}
	return (NULL);
}
