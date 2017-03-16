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
		(ls[fd])->str = NULL;
		(ls[fd])->clr = NULL;
		(ls[fd])->end = 0;
		(ls[fd])->r_len = 0;
	}
}

int			get_next_line(int fd, char **line)
{
	char			*buf;
	static t_list_n	*ls[5000];
	char			*n;

	n = NULL;
	if (fd < 0 || !line || BUF_SIZE < 1)//|| !(buf = ft_strnew(BUF_SIZE))
		return (-1);
    buf = ft_strnew(BUF_SIZE);
	init_it(ls, fd);
	while ((n = ft_strchr((ls[fd])->str, '\n')) == NULL &&
		((ls[fd])->r_len = read(fd, ((ls[fd])->str) ? buf : ((ls[fd])->str = ft_strnew(BUF_SIZE)), BUF_SIZE)) == BUF_SIZE
		&& !(n = ft_strchr((ls[fd])->str, '\n')))
	{
		((ls[fd])->clr) = (ls[fd])->str;
		(ls[fd])->str = ft_strjoin((ls[fd])->str, buf);
		//ft_strdel(&((ls[fd])->clr));
		ft_bzero(buf, BUF_SIZE + 1);
	}
	((ls[fd])->clr) = (ls[fd])->str;
	if (*buf)
	{
		(ls[fd])->str = ft_strjoin((ls[fd])->str, buf);
		//ft_strdel(&((ls[fd])->clr));
	}
	if ((ls[fd])->r_len < 0)
	{
		//ft_strdel(&((ls[fd])->str));
		ft_strdel(&buf);
		return (-1);
	}
	if ((ls[fd])->r_len == 0 && (ls[fd])->str &&((ls[fd])->str[0] == '\0'))
	{
		ft_strdel(&((ls[fd])->str));
		ft_strdel(&buf);
		return (0);
	}
	
	n = ft_strchr((ls[fd])->str, '\n');
	if (!n)
	{
		*line = ft_strdup((ls[fd])->str);
		(ls[fd])->str = ft_strnew(0);
	}
	else
	{
		// int z = n - (ls[fd])->str;
		// *line = ft_strsub((ls[fd])->str, 0, z);
		// int a = n - (ls[fd])->str + 1;
		// int b = ft_strlen((ls[fd])->str);
		// (ls[fd])->str = ft_strsub((ls[fd])->str, a, b);
		*line = ft_strsub((ls[fd])->str, 0, n - (ls[fd])->str);
		(ls[fd])->str = ft_strsub((ls[fd])->str, n - (ls[fd])->str + 1, ft_strlen((ls[fd])->str));
	}
	ft_strdel(&((ls[fd])->clr));
	ft_strdel(&buf);
	return (1);
}

