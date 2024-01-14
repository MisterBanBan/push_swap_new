# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afavier <afavier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 09:38:55 by afavier           #+#    #+#              #
#    Updated: 2024/01/11 02:41:44 by afavier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES =	atoi.c \
			swap.c \
			three.c \
			two.c \
			push_swap_main.c \
			push.c \
			rotate.c \
			creat_tab_swap.c \
			reverse_rotate.c \
			parsing.c \
			sort_prog.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

$(NAME): $(OBJECTS)
		cc $(OBJECTS) -o $(NAME)

all: $(NAME)

%.o: %.c push_swap.h
		cc $(CFLAGS) -c $< -o $@
clean:
		rm -f $(OBJECTS)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: clean fclean re all