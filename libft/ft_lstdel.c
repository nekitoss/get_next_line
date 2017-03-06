/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:48:17 by nekitoss          #+#    #+#             */
/*   Updated: 2016/12/07 16:48:19 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		if ((*alst)->next)
			tmp = (*alst)->next;
		else
			tmp = NULL;
		free(*alst);
		*alst = tmp;
	}
	alst = NULL;
}
