# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 20:22:48 by yejeon            #+#    #+#              #
#    Updated: 2020/11/03 20:22:48 by yejeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
TARGET	= a.out
OBJS	= *.o

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

*.o:	*.c
		gcc ${CFLAGS} -c *.c

clean:
	rm $(OBJS) $(TARGET)
