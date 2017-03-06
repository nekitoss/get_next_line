/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:05:30 by nekitoss          #+#    #+#             */
/*   Updated: 2016/12/01 21:05:31 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	char	tmp;
	size_t	i;

	i = 0;
	if (s && f)
	{
		new_str = ft_strnew(ft_strlen(s));
		if (new_str)
			while (*s)
			{
				tmp = f(*s++);
				if (tmp)
					new_str[i++] = tmp;
			}
		return (new_str);
	}
	return (NULL);
}
