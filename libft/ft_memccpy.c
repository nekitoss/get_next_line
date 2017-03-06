/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:42:06 by nekitoss          #+#    #+#             */
/*   Updated: 2016/11/25 19:42:07 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*u_dst;
	unsigned char	*u_src;
	unsigned char	u_c;

	u_c = (unsigned char)c;
	u_dst = (unsigned char *)dst;
	u_src = (unsigned char *)src;
	while (n > 0)
	{
		if (*u_src == u_c)
		{
			*u_dst = *u_src;
			return (++u_dst);
		}
		*u_dst = *u_src;
		u_dst++;
		u_src++;
		n--;
	}
	return (NULL);
}
