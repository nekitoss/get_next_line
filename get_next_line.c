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

void	init_it(t_list_n **ls, int fd)
{
	if (!(ls[fd]))
	{
		(ls[fd]) = (t_list_n *)malloc(sizeof(t_list_n));
		(ls[fd])->str = ft_strnew(BUF_SIZE);
		(ls[fd])->clr = NULL;
		(ls[fd])->end = 0;
		(ls[fd])->r_len = 0;
	}
}

void	cut_it(t_list_n **ls, int fd, char **line)
{
	char *n;

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
}

int			get_next_line(int fd, char **line)
{
	char			*buf;
	static t_list_n	*ls[5000];
	char			*n;

	n = NULL;
	if (fd < 0 || !line || !(buf = ft_strnew(BUF_SIZE)) || BUF_SIZE < 1)
		return (-1);
	init_it(ls, fd);
	while ((n = ft_strchr((ls[fd])->str, '\n')) == NULL && ((ls[fd])->r_len = read(fd, buf, BUF_SIZE)) == BUF_SIZE)
	{
		(ls[fd])->str = ft_strjoin((ls[fd])->str, buf);
		ft_bzero(buf, BUF_SIZE + 1);
	}
	if (*buf)
		(ls[fd])->str = ft_strjoin((ls[fd])->str, buf);
	if ((ls[fd])->r_len < 0)
		return (-1);
	if ((ls[fd])->r_len == 0 && (ls[fd])->str &&((ls[fd])->str[0] == '\0'))
		return (0);
	cut_it(ls, fd, line);
	return (1);
}

