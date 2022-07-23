# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 16:03:31 by kyoon             #+#    #+#              #
#    Updated: 2022/07/23 13:53:04 by kyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SOURCES = ./so_long.c\
		  ./move.c\
		  ./progress.c\
		  ./validation.c\
		  ./draw.c

LIBFT = libft.a
OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) -L./minilibx -lmlx -framework OpenGL -framework AppKit -o $@ $^

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
