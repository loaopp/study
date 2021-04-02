NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = gcc

LIBFT = libft.a
LIBFT_DIR = lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CFLAGS += -I $(LIBFT_DIR)
CFLAGS += -I ./inc/

FILES = main \
		push_swap \
		stack_util \
		lst_util \
		util \
		util2 \
		sort_util \
		sort_util2 \
		pin_1_util \
		pin_2_util \
		sort_down_5 \
		push_swap_util \
		checker2 \
		shit

C_SRCS = srcs/stack_util.c \
		 srcs/lst_util.c \
		 srcs/util.c \
		 srcs/util2.c \
		 srcs/sort_util.c \
		 srcs/sort_util2.c \
		 srcs/push_swap.c \
		 srcs/pin_1_util.c \
		 srcs/pin_2_util.c \
		 srcs/sort_down_5.c \
		 srcs/push_swap_util.c \
		 srcs/checker.c \
		 srcs/checker2.c \
		 srcs/shit.c
			
SRCS = $(addprefix srcs/, $(addsuffix .c, $(FILES))) 

OBJS = $(SRCS:.c=.o)

C_OBJS = $(C_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(C_OBJS)
	$(MAKE) -C ./lib/libft
	$(CC) $(CFLAGS) -o push_swap $(SRCS) $(LIBFT_FLAGS)
	$(CC) $(CFLAGS) -o checker $(C_SRCS) $(LIBFT_FLAGS)
	
clean :
	$(MAKE) clean -C ./lib/libft
	rm -rf $(SURP)
	rm -f $(OBJS) $(C_OBJS)

fclean :
	$(MAKE) fclean -C ./lib/libft
	rm -f $(OBJS) $(C_OBJS) $(NAME) checker
	
re : fclean all

.PHONY: clean fclean all re bonus
