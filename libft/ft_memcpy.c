/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:21:56 by nekitoss          #+#    #+#             */
/*   Updated: 2016/11/25 19:21:56 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;

	str = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	while (n > 0)
	{
		*str = (unsigned char)*str2;
		str++;
		str2++;
		n--;
	}
	return (dst);
}
