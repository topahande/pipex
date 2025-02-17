# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 13:01:18 by htopa             #+#    #+#              #
#    Updated: 2024/10/31 15:26:20 by htopa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_B = pipex_bonus

SRCS = pipex.c \
	utils.c \
	print_error_messages.c \

SRCSB =	pipex_bonus.c \
	utils_bonus.c \
	print_error_messages_bonus.c \
	handle_pipes_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

CC = cc
CC_FLAGS = -Wall -Wextra -Werror

libft = libft/libft.a

%.o : %.c
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(libft)
	@$(CC) $(CC_FLAGS) $(OBJS) ${libft} -o ${NAME}
	echo "Pipex Done !"

$(libft):
	make -C libft

bonus: $(NAME_B)

$(NAME_B): $(OBJSB) $(libft)
	@$(CC) $(CC_FLAGS) $(OBJSB) ${libft} -o ${NAME}
	echo "Pipex Bonus Done!"

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(OBJSB)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
