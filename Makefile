# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 19:13:31 by tvermeil          #+#    #+#              #
#    Updated: 2016/01/14 16:53:20 by tvermeil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS += -Wall -Wextra -Werror -I libft -g
LDFLAGS += -L libft -lft
SRCS =     	push_swap.c \
			pile.c \
			operation.c \
			display.c \
			list_util.c \
			solver.c \
			string_utils.c \
			advenced_operations.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

libft:
	make -C libft all

$(NAME): $(OBJS)
	gcc -I libft $(OBJS) -L libft -lft -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re libft
