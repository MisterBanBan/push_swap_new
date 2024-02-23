# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afavier <afavier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 09:38:55 by afavier           #+#    #+#              #
#    Updated: 2024/02/02 12:54:56 by afavier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
BONUS := checker
SRC_DIR := src
BUILD_DIR := .build
DEPS_DIR := .deps
INC := inc/push_swap.h

BONUS = checker

ORDER =	$(SRC_DIR)/order/push.c \
		$(SRC_DIR)/order/reverse_rotate.c \
		$(SRC_DIR)/order/rotate.c \
		$(SRC_DIR)/order/three.c \
		$(SRC_DIR)/order/swap.c


PUSH_SWAP :=	$(SRC_DIR)/push_swap/allow_tab.c \
				$(SRC_DIR)/push_swap/ft_atol.c \
				$(SRC_DIR)/push_swap/push_swap_main.c \
				$(SRC_DIR)/push_swap/sort_swap.c \
				$(SRC_DIR)/push_swap/swap.c

SRC := 	$(ORDER) \
		$(PUSH_SWAP)

OBJS    := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEPS    := $(patsubst %.o, %.d,$(OBJS))


LIBS       				:= libft
LIBS_TARGET 			:= libft/libft.a

CC					    := cc
CFLAGS					:= -Wall -Wextra -Werror
CPPFLAGS 				:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS 				:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS  				:= -L$(LIBS) -lft

# BONUS ***************************************************************************** #
BONUS_DIR		:= 	$(SRC_DIR)/bonus/order/push_bonus.c					\
					$(SRC_DIR)/bonus/order/reverse_rotate_bonus.c \
					$(SRC_DIR)/bonus/order/rotate_bonus.c \
					$(SRC_DIR)/bonus/order/swap_bonus.c \
					$(SRC_DIR)/bonus/push_swap/check_sort_bonus.c \
					$(SRC_DIR)/bonus/push_swap/ft_atol_bonus.c \
					$(SRC_DIR)/bonus/push_swap/ft_strcmp_bonus.c \
					$(SRC_DIR)/bonus/push_swap/parsing_bonus.c \
					$(SRC_DIR)/bonus/push_swap/push_swap_bonus.c \
					$(SRC_DIR)/bonus/push_swap/sort_tab_bonus.c

SRCS_BONUS		:= $(BONUS_DIR)
OBJS_BONUS		:= $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS_BONUS))
DEPS_BONUS		:= $(patsubst %.o, %.d,$(OBJS))


RM := rm -f

all: $(NAME) 

force:


$(LIBS_TARGET): force
	@$(MAKE) -C $(@D) --no-print-directory

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBS_TARGET)
			$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

bonus: $(OBJS_BONUS) $(LIBS_TARGET)
			$(CC) $(LDFLAGS) $(OBJS_BONUS) $(LDLIBS) -o $(BONUS)

-include $(DEPS)
# **************************************************************************** #
CLEAN_DIRS := libft/
clean:
	$(MAKE) -C $(CLEAN_DIRS) clean
	$(RM) -r $(BUILD_DIR) $(DEPS_DIR)
# **************************************************************************** #
fclean:
	$(MAKE) -C $(CLEAN_DIRS) fclean
	$(RM) -r $(BUILD_DIR) $(DEPS_DIR) $(NAME) $(BONUS)
# **************************************************************************** #
re: fclean all
# **************************************************************************** # # .PHONY #
.PHONY: all clean fclean re bonus
# *****************************
