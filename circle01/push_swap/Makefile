# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 16:03:31 by kyoon             #+#    #+#              #
#    Updated: 2022/05/25 18:06:01 by kyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libftprintf.a
SOURCES = ./push_swap.c\

LIBFT = libft
LIBFT_LIB = libft.a

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	make all -C ./libft/
	cp ./libft/libft.a $(NAME)
	ar -cr $@ $^

all: $(NAME)

clean:
	rm -f $(OBJECTS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY : all clean fclean re
