# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 16:03:31 by kyoon             #+#    #+#              #
#    Updated: 2022/06/25 13:24:01 by kyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libftprintf.a
SOURCES = ./ft_printf.c\
		  ./ft_printf_utils.c\
		  ./ft_printf_itoa.c\
		  ./ft_full_width.c\
		  ./ft_print_hex.c\
		  ./ft_print_nums.c\
		  ./ft_print_words.c\
		  ./ft_printf_setting.c\
		  ./ft_base.c\
		  ./ft_printf_n.c\
		  ./ft_va_input.c\

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
