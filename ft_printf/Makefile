# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 00:21:32 by yejeon            #+#    #+#              #
#    Updated: 2021/03/25 09:17:06 by yejeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

DIR_LIBFT	=	./libft
DIR_SRC		=	./
DIR_OBJ		=	./
LIBFTLIB	=	libft.a
SRCS		=	ft_printf.c \
				print_str.c \
				print_int.c	\
				print_pointer.c \
				printf_util.c
OBJS		=	$(SRCS:.c=.o)

all:	$(NAME)

.c.o:	$(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(DIR_SRC)

$(NAME):	$(OBJS)
	make all -C $(DIR_LIBFT)
	cp $(DIR_LIBFT)/$(LIBFTLIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(DIR_LIBFT)

clean:
	rm -f $(OBJS)
	make clean -C $(DIR_LIBFT)

re:	fclean all

.PHONY:	all clean fclean re bonus
