# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 16:03:31 by kyoon             #+#    #+#              #
#    Updated: 2022/06/06 21:41:24 by kyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk
C_NAME = client
S_NAME = server 
LIBFT = libft.a
C_SOURCES = ./client.c
S_SOURCES = ./server.c
BONUS_C_S = ./client_bonus.c
BONUS_S_S = ./server_bonus.c

C_OBJECTS = $(C_SOURCES:.c=.o)
S_OBJECTS = $(S_SOURCES:.c=.o)
BONUS_C_O = $(BONUS_C_S:.c=.o)
BONUS_S_O = $(BONUS_S_S:.c=.o)

ifdef IS_BONUS
	TARGET_C_OBJECTS = $(BONUS_C_O)
	TARGET_S_OBJECTS = $(BONUS_S_O)
else
	TARGET_C_OBJECTS = $(C_OBJECTS)
	TARGET_S_OBJECTS = $(S_OBJECTS)
endif
	
$(NAME): $(C_NAME) $(S_NAME)

all: $(NAME)

$(LIBFT):
	make all -C ./libft/
	mv ./libft/libft.a $(LIBFT)

$(C_NAME): $(LIBFT) $(TARGET_C_OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $^

$(S_NAME): $(LIBFT) $(TARGET_S_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

bonus: $(LIBFT) 
	$(MAKE) IS_BONUS=1 $(NAME)

clean:
	rm -f $(C_OBJECTS) $(S_OBJECTS) $(BONUS_C_O) $(BONUS_S_O)
	make clean -C ./libft

fclean: clean
	rm -f $(C_NAME) $(S_NAME) $(LIBFT)
	make fclean -C ./libft

re: fclean all

.PHONY : all clean fclean re bonus
