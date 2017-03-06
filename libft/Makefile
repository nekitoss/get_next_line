#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nekitoss <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/27 15:19:20 by nekitoss          #+#    #+#              #
#    Updated: 2016/11/27 15:19:23 by nekitoss         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra -I$(INCL) -c 

SRC = ft_bzero.c\
		ft_isdigit.c\
		ft_memset.c\
		ft_strcmp.c\
		ft_strlen.c\
		ft_strnstr.c\
		ft_toupper.c\
		ft_isalnum.c\
		ft_isprint.c\
		ft_strcat.c\
		ft_strcpy.c\
		ft_strncat.c\
		ft_strrchr.c\
		ft_isalpha.c\
		ft_memccpy.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strncmp.c\
		ft_strstr.c\
		ft_atoi.c\
		ft_isascii.c\
		ft_memcpy.c\
		ft_strclr.c\
		ft_strlcat.c\
		ft_strncpy.c\
		ft_tolower.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_strcstr.c\
		ft_str_un_i_chr.c\
		ft_str_i_chr.c\
		ft_itoa.c\
		ft_lstnew.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c

BIN = $(SRC:.c=.o)

INCL = ./libft.h

.PHONY: clean fclean re

$(NAME):
	$(CC) $(CFLAGS) $(SRC)
	ar rc $(NAME) $(BIN)
	ranlib $(NAME)

all: $(NAME) 
	
clean:
	/bin/rm -f $(BIN)

fclean: clean
	/bin/rm -f $(NAME)	

re: fclean all
