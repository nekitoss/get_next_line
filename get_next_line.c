/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:28:54 by nekitoss          #+#    #+#             */
/*   Updated: 2017/01/31 17:28:55 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

t_list_n	*init_it(t_list_n **head, int fd)
{
	t_list_n	*tmp;

	if (!(*head))
	{
		*head = (t_list_n *)malloc(sizeof(t_list_n));
		(*head)->fd = fd;
		(*head)->next = NULL;
		(*head)->str = NULL;
		(*head)->end = 0;
		return (*head);
	}
	tmp = (*head);
	while (fd != tmp->fd && tmp->next)
		tmp = tmp->next;
	if (fd == tmp->fd)
		return (tmp);
	tmp->next = (t_list_n *)malloc(sizeof(t_list_n));
	tmp->next->fd = fd;
	tmp->next->next = NULL;
	tmp->next->str = NULL;
	tmp->next->end = 0;
	return (tmp->next);
}

int			get_next_line(int fd, char **line)
{
	char			*buf;
	static t_list_n	*head;
	t_list_n		*curr;
	char			*n;

	n = NULL;
	if (fd < 0 || !line || !(buf = ft_strnew(BUF_SIZE)) || BUF_SIZE < 1)
		return (-1);
	curr = init_it(&head, fd);
	while ((n = ft_strchr(curr->str, '\n')) == NULL &&
		(curr->r_len = read(fd, (curr->str) ? buf : (curr->str = ft_strnew(BUF_SIZE)), BUF_SIZE)) == BUF_SIZE
		&& !(n = ft_strchr(curr->str, '\n')))
	{
		(curr->clr) = curr->str;
		curr->str = ft_strjoin(curr->str, buf);
		//ft_strdel(&(curr->clr));
		ft_bzero(buf, BUF_SIZE + 1);
	}
	if (*buf)
		curr->str = ft_strjoin(curr->str, buf);
	if (curr->r_len < 0)
		return (-1);
	if (curr->r_len == 0 && (curr->str[0] == '\0'))
	{
		ft_strdel(&(curr->str));
		ft_strdel(&buf);
		return (0);
	}
	(curr->clr) = curr->str;
	n = ft_strchr(curr->str, '\n');
	if (!n)
	{
		*line = ft_strdup(curr->str);
		curr->str = ft_strnew(0);
	}
	else
	{
		*line = ft_strsub(curr->str, 0, n - curr->str);
		curr->str = ft_strsub(curr->str, n - curr->str + 1, ft_strlen(curr->str));
	}
	ft_strdel(&(curr->clr));
	ft_strdel(&buf);
	return (1);
}
