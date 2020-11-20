# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/14 09:49:10 by yejeon            #+#    #+#              #
#    Updated: 2020/11/14 10:27:11 by yejeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	get_next_line.out
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
DIR_SRCS	=	./
DIR_OBJS	=	./
DIR_HDRS	=	./
SRCS		=	get_next_line.c	\
				get_next_line_utils.c
OBJS		=	$(SRCS:.c,.o)

all:	$(NAME)

.c.o:	$(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) *.o

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: clean all

.PHONY:	all clean fclean re
