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

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static t_list_n	*head;
	t_list_n		*curr;
	char		*n;

	n = NULL;
	if (fd < 0 || !line || !(buf = ft_strnew(BUF_SIZE)) || BUF_SIZE < 1)
		return (-1);
	curr = init_it(&head, fd);
	

    //curr->r_len = read(fd, (curr->str) ? buf : (curr->str = ft_strnew(BUF_SIZE)), BUF_SIZE);
	while ((n = ft_strchr(curr->str, '\n')) == NULL &&
        (curr->r_len = read(fd, (curr->str) ? buf : (curr->str = ft_strnew(BUF_SIZE)), BUF_SIZE)) == BUF_SIZE
        &&
        !(n = ft_strchr(curr->str, '\n'))
           )//           ||           !(n = ft_strchr(buf, '\n'))           )
	{
       //if ((n = ft_strchr(curr->str, '\n')) != NULL)
       //     break ;
		
		//curr->r_len = read(fd, buf, BUF_SIZE);
		curr->clr = curr->str;
		curr->str = ft_strjoin(curr->str, buf);
		ft_strdel(&(curr->clr));
        ft_bzero(buf, BUF_SIZE + 1);
	}
    
    if (*buf)
        curr->str = ft_strjoin(curr->str, buf);
	//ft_strdel(&buf);
	//if ((curr->r_len < BUF_SIZE && (curr->r_len = read(fd, buf, BUF_SIZE)) == 0) && !(curr->str[0]) && n != (ft_strchr(curr->str, '\0')))
    if (curr->r_len < 0)
        return (-1);
    if (
         curr->r_len == 0
         &&
         (curr->str[0] == '\0')
         //&&
         //(curr->r_len = read(fd, buf, BUF_SIZE)) == 0
        )
	{/*
		if ((curr->str[0]) && n != (ft_strchr(curr->str, '\0')))
			*line = ft_strsub(curr-> str, 0, n - (curr->str));
		else
        {*/
			//*line = ft_strnew(0);
            ft_strdel(&buf);

            return (0);
        //}
       /* if (curr->end)
            return (0);
        else
        {
            curr->end = 1;
            return (1);
        }*/
	}
	//ft_strdel(&buf);
//	EOF == read(fd, buf, BUF_SIZE);
	curr->clr = curr->str;
    n = ft_strchr(curr->str, '\n');
    if (!n)
    {
        *line = ft_strdup(curr->str);
        curr->str = ft_strnew(0);
        
    }
    else
    {
        //printf("str=%s\n", curr->str);
        *line = ft_strsub(curr->str, 0, n - curr->str);
//        if (!(**line))
//        {
//            curr->str = curr->clr;
//            *line = ft_strsub(curr->str, 0, n - curr->str);
//        }
//        printf("line=%s\n", *line);
        curr->str = ft_strsub(curr->str, n - curr->str + 1, ft_strlen(curr->str));
    }
    //curr->str = n++;

    ft_strdel(&(curr->clr));
    ft_strdel(&buf);

	return (1);
}




 int		main(void)
{

    char	*line;
    int r;
    
    r = 1;
    int fd1 = open("text.txt", O_RDONLY);
    //	int fd2 = open("text2", O_RDONLY);
    
//    int			fd;
//    int			ret;
//    int			count_lines;
//    char		*filename;
//    int			errors;
//    
//    filename = "/nfs/2016/m/nekitoss/Desktop/getnextline/getnextline/text.txt";
//    fd = open(filename, O_RDONLY);
//    if (fd > 2)
//    {
//        count_lines = 0;
//        errors = 0;
//        line = NULL;
//        while ((ret = get_next_line(fd, &line)) > 0)
//        {
//            if (count_lines == 0 && strcmp(line, "1234567890abcde") != 0)
//                errors++;
//            if (count_lines == 1 && strcmp(line, "fghijklmnopqrst") != 0)
//                errors++;
//            count_lines++;
//            if (count_lines > 50)
//                break ;
//        }
//        close(fd);
//        if (count_lines != 2)
//            printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
//        if (errors > 0)
//            printf("-> must have read \"1234567890abcde\" and \"fghijklmnopqrst\"\n");
//        if (count_lines == 2 && errors == 0)
//            printf("OK\n");
//    }
//    else
//        printf("An error occured while opening file %s\n", filename);
//    return (0);
    
   
 
    while (r > 0)
    {
        r = get_next_line(fd1, &line);
        printf("%s|", line);
        printf("r=%d\n", r);
        line = NULL;
    }
 
    return (0);
     
}


