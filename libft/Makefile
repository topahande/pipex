# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 12:53:31 by htopa             #+#    #+#              #
#    Updated: 2024/10/14 13:31:54 by htopa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strlen.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_printf.c \
		ft_putchar.c \
		ft_puthexadecimal.c \
		ft_putnbr_base.c \
		ft_putnbr_positive.c \
		ft_putnbr.c \
		ft_putpercent.c \
		ft_putpointer.c \
		ft_putstr.c \
		ft_putunsignednbr_check.c \
		ft_putunsignednbr.c \

SRCSB =	ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

%.o : %.c
	@$(CC) $(CC_FLAGS) -c $< -o $@  

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	echo "Libft Done !"

bonus: .bonus

.bonus: $(OBJS) $(OBJSB)
	ar rcs $(NAME) $(OBJS) $(OBJSB)
	echo "Libft Bonus Done !"
	touch .bonus

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(OBJSB)
	rm -f .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all bonus

.PHONY: all clean fclean re bonus
