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

void	init_it(t_list_n *list)
{
	if (!list)
	{
		list = (t_list_n *)malloc(sizeof(t_list_n));
		list->str = NULL;
		list->clr = NULL;
		list->end = 0;
		list->r_len = 0;
	}
}

int			get_next_line(int fd, char **line)
{
	char			*buf;
	static t_list_n	*ls[5000];
	char			*n;

	n = NULL;
	if (fd < 0 || !line || !(buf = ft_strnew(BUF_SIZE)) || BUF_SIZE < 1)
		return (-1);
	init_it((ls[fd]));
	while ((n = ft_strchr((ls[fd])->str, '\n')) == NULL &&
		((ls[fd])->r_len = read(fd, ((ls[fd])->str) ? buf : ((ls[fd])->str = ft_strnew(BUF_SIZE)), BUF_SIZE)) == BUF_SIZE
		&& !(n = ft_strchr((ls[fd])->str, '\n')))
	{
		((ls[fd])->clr) = (ls[fd])->str;
		(ls[fd])->str = ft_strjoin((ls[fd])->str, buf);
		//ft_strdel(&((ls[fd])->clr));
		ft_bzero(buf, BUF_SIZE + 1);
	}
	if (*buf)
		(ls[fd])->str = ft_strjoin((ls[fd])->str, buf);
	if ((ls[fd])->r_len < 0)
		return (-1);
	if ((ls[fd])->r_len == 0 && ((ls[fd])->str[0] == '\0'))
	{
		ft_strdel(&((ls[fd])->str));
		ft_strdel(&buf);
		return (0);
	}
	((ls[fd])->clr) = (ls[fd])->str;
	n = ft_strchr((ls[fd])->str, '\n');
	if (!n)
	{
		*line = ft_strdup((ls[fd])->str);
		(ls[fd])->str = ft_strnew(0);
	}
	else
	{
		*line = ft_strsub((ls[fd])->str, 0, n - (ls[fd])->str);
		(ls[fd])->str = ft_strsub((ls[fd])->str, n - (ls[fd])->str + 1, ft_strlen((ls[fd])->str));
	}
	ft_strdel(&((ls[fd])->clr));
	ft_strdel(&buf);
	return (1);
}
