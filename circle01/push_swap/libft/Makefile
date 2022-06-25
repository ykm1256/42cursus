# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 16:03:31 by kyoon             #+#    #+#              #
#    Updated: 2022/06/25 13:13:10 by kyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libft.a
SOURCES = ./ft_memset.c\
		  ./ft_bzero.c\
		  ./ft_memcpy.c\
		  ./ft_memccpy.c\
		  ./ft_strlen.c\
		  ./ft_strlcpy.c\
		  ./ft_strlcat.c\
		  ./ft_atoi.c\
		  ./ft_memmove.c\
		  ./ft_strchr.c\
		  ./ft_memchr.c\
		  ./ft_memcmp.c\
		  ./ft_strrchr.c\
		  ./ft_strnstr.c \
		  ./ft_strncmp.c\
		  ./ft_isalpha.c\
		  ./ft_isdigit.c\
		  ./ft_isalnum.c\
		  ./ft_isascii.c\
		  ./ft_isprint.c\
		  ./ft_toupper.c\
		  ./ft_tolower.c\
		  ./ft_calloc.c\
		  ./ft_strdup.c\
		  ./ft_substr.c\
		  ./ft_strjoin.c\
		  ./ft_strtrim.c\
		  ./ft_split.c\
		  ./ft_itoa.c\
		  ./ft_strmapi.c\
		  ./ft_putchar_fd.c\
		  ./ft_putstr_fd.c\
		  ./ft_putendl_fd.c\
		  ./ft_putnbr_fd.c\

BONUS_SOURCES = ./ft_lstnew.c\
			 	./ft_lstadd_front.c\
			 	./ft_lstsize.c\
				./ft_lstlast.c\
				./ft_lstadd_back.c\
				./ft_lstdelone.c\
				./ft_lstclear.c\
				./ft_lstiter.c\
			 	./ft_lstmap.c

.PHONY : all clean fclean re bonus
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

ifdef IS_BONUS
	C_OBJECTS = $(BONUS_OBJECTS)
else
	C_OBJECTS = $(OBJECTS)
endif


$(NAME): $(C_OBJECTS)
	ar -cr $@ $^

all: bonus $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

bonus:
		$(MAKE) IS_BONUS=1 $(NAME)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
