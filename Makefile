# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 19:13:31 by tvermeil          #+#    #+#              #
#    Updated: 2016/02/29 22:23:45 by tvermeil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CPPFLAGS = -I include
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L.
LDLIBS = -lft

SRC_PATH = src
INC_PATH = include
OBJ_PATH = obj/$(NAME)

MAKEFLAGS += --no-print-directory

SRC_NAME =	push_swap.c \
			pile.c \
			operation.c \
			display.c \
			list_util.c \
			solver.c \
			string_utils.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo -n .

all: $(NAME)

libft.a: $(LIBFT_OBJ)
	@make -C libft all

$(NAME): libft.a $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo " . \033[32m$(NAME)\033[0m done"

clean:
	@make -C libft clean
	@-rm -fv $(LIBFT_OBJ) $(OBJ)
	@rmdir $(LIBFT_OBJ_PATH) $(OBJ_PATH) obj 2> /dev/null || true

fclean: clean
	@make -C libft fclean
	@-rm -fv $(NAME)

re: fclean all

ac: all clean

norme:
	norminette $(LIBFT_SRC) $(SRC) include/*.h

.PHONY: all clean fclean re
