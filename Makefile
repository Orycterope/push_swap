# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 19:13:31 by tvermeil          #+#    #+#              #
#    Updated: 2016/02/10 21:26:58 by tvermeil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CPPFLAGS = -I include
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L.
LDLIBS = -lft

SRC_PATH = src
INC_PATH = include
OBJ_PATH = obj/$(NAME)
LIBFT_SRC_PATH = libft
LIBFT_OBJ_PATH = obj/libft

SRC_NAME =	push_swap.c \
			pile.c \
			operation.c \
			display.c \
			list_util.c \
			solver.c \
			string_utils.c \

LIBFT_NAME =    ft_memset.c \
		    	ft_bzero.c \
   		    	ft_memcpy.c \
   		    	ft_memccpy.c \
   		    	ft_memmove.c \
   		    	ft_memchr.c \
   		    	ft_memcmp.c \
   		    	ft_strlen.c \
   		    	ft_strdup.c \
   		    	ft_strcpy.c \
   		    	ft_strncpy.c \
   		    	ft_strcat.c \
   		    	ft_strncat.c \
   		    	ft_strlcat.c \
   		    	ft_strchr.c \
   		    	ft_strrchr.c \
   		    	ft_strstr.c \
   		    	ft_strnstr.c \
   		    	ft_strcmp.c \
   		    	ft_strncmp.c \
   		    	ft_atoi.c \
   		    	ft_isalpha.c \
   		    	ft_isdigit.c \
   		    	ft_isalnum.c \
   		    	ft_isascii.c \
   		    	ft_isprint.c \
   		    	ft_toupper.c \
   		    	ft_tolower.c \
   		    	ft_memalloc.c \
   		    	ft_memdel.c \
   		    	ft_strnew.c \
   		    	ft_strdel.c \
   		    	ft_strclr.c \
   		    	ft_striter.c \
   		    	ft_striteri.c \
   		    	ft_strmap.c \
   		    	ft_strmapi.c \
   		    	ft_strequ.c \
   		    	ft_strnequ.c \
   		    	ft_strsub.c \
   		    	ft_strjoin.c \
   		    	ft_strjoin_free.c \
   		    	ft_strtrim.c \
   		    	ft_strsplit.c \
   		    	ft_itoa.c \
   		    	ft_putchar.c \
   		    	ft_putstr.c \
   		    	ft_putendl.c \
   		    	ft_putnbr.c \
   		    	ft_putchar_fd.c \
   		    	ft_putstr_fd.c \
   		    	ft_putendl_fd.c \
   		    	ft_putnbr_fd.c \
   		    	ft_lstnew.c \
   		    	ft_lstdelone.c \
   		    	ft_lstdel.c \
   		    	ft_lstadd.c \
   		    	ft_lstiter.c \
   		    	ft_lstmap.c \

OBJ_NAME = $(SRC_NAME:.c=.o)
LIBFT_OBJ_NAME = $(LIBFT_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIBFT_SRC = $(addprefix $(LIBFT_SRC_PATH)/,$(LIBFT_NAME))
LIBFT_OBJ = $(addprefix $(LIBFT_OBJ_PATH)/,$(LIBFT_OBJ_NAME))

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT_OBJ_PATH)%.o: $(LIBFT_SRC_PATH)%.c
	@mkdir -p $(LIBFT_OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

libft.a: $(LIBFT_OBJ)
	ar rcs libft.a $(LIBFT_OBJ)

$(NAME): $(OBJ) libft.a
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

clean:
	@-rm -fv $(LIBFT_OBJ) $(OBJ)
	@rmdir $(LIBFT_OBJ_PATH) $(OBJ_PATH) obj 2> /dev/null || true

fclean: clean
	@-rm -fv $(NAME) libft.a

re: fclean all

ac: all clean

norme:
	norminette $(LIBFT_SRC) $(SRC) include/*.h

.PHONY: all clean fclean re
