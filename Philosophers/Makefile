# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 14:12:02 by dramos-j          #+#    #+#              #
#    Updated: 2024/10/20 11:06:29 by dramos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Philosophers
CC = cc
CFLAGS = -Wall -Wextra -Werror $(EXTRAFLAGS)
EXTRAFLAGS = -pthread
SRCS = main.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
