# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 13:28:55 by crisfern          #+#    #+#              #
#    Updated: 2022/02/21 14:41:20 by crisfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADER = pipex.h

LIBFT_DIR = ./libft/

LIBFT = ./libft/libft.a

SRC = pipex.c

OBJ = $(SRC:.c=.o)

all: make_libft $(NAME)

make_libft:
	@make all -C $(LIBFT_DIR)

$(NAME):  $(OBJ)
	$(CC) $(CFLAGS) $< $(LIBFT) -o $@

%.o: %.c $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) $< -c

clean:
	@rm -rf $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.phony: all make_libft clean fclean re