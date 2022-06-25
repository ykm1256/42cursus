# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 16:03:31 by kyoon             #+#    #+#              #
#    Updated: 2022/06/25 14:42:59 by kyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SOURCES = ./push_swap.c\
		  ./opers.c\
		  ./rrotate.c\
		  ./sort.c\
		  ./dequtil.c\
		  ./progress.c\
		  ./validation.c\
		  ./rotate.c\
		  ./lowprogress.c

LIBFT = libft.a
OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

$(LIBFT):
	make all -C ./libft/
	mv ./libft/libft.a $(LIBFT)

clean:
	rm -f $(OBJECTS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME) $(LIBFT)
	make fclean -C ./libft

re: fclean all

.PHONY : all clean fclean re
