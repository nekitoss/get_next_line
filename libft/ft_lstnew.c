/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:50:05 by nekitoss          #+#    #+#             */
/*   Updated: 2016/12/07 16:50:05 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		new->next = NULL;
		if (content)
		{
			new->content = (void *)malloc(content_size);
			ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
			return (new);
		}
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	return (NULL);
}
