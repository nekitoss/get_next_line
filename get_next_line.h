/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:06:13 by nekitoss          #+#    #+#             */
/*   Updated: 2017/02/15 14:06:18 by nekitoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUF_SIZE 1
# include "./libft.h"

typedef struct	s_lost
{
	char			*str;
	int				r_len;
	char			*clr;
	int				end;
}				t_list_n;

int				get_next_line(int fd, char **line);

#endif
