# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 19:13:31 by tvermeil          #+#    #+#              #
#    Updated: 2016/02/29 20:45:03 by tvermeil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libft.a

SRC_PATH = .
INC_PATH = ../include
OBJ_PATH = ../obj/libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I $(INC_PATH)

SRC_NAME =    ft_memset.c \
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

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo -n .

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo " . \033[32mlibft.a\033[0m done"

clean:
	@-cd .. && rm -fv $(addprefix obj/libft/,$(OBJ_NAME))
	@rmdir $(OBJ_PATH) ../obj 2> /dev/null || true

fclean: clean
	@-cd .. && rm -fv libft.a

re: fclean all

ac: all clean

norme:
	norminette $(SRC)

.PHONY: all clean fclean re
