# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 16:03:31 by kyoon             #+#    #+#              #
#    Updated: 2022/07/14 17:31:08 by kyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SOURCES = ./so_long.c\

OBJECTS = $(SOURCES:.c=.o)


all:
	$(CC) -L./minilibx -lmlx -framework OpenGL -framework AppKit so_long.c libft/*.c

.PHONY : all clean fclean re
