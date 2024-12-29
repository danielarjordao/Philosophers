# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 14:12:02 by dramos-j          #+#    #+#              #
#    Updated: 2024/12/26 12:18:57 by dramos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror $(EXTRAFLAGS)
EXTRAFLAGS = -pthread
SRCS = main.c init.c check_args.c routine.c routine_utils.c monitor.c utils.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	@echo "Compiling philo..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up object files..."
	$(RM) $(OBJS)

fclean: clean
	@echo "Cleaning up compiled files..."
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
