# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 14:12:02 by dramos-j          #+#    #+#              #
#    Updated: 2024/12/15 17:01:51 by dramos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror $(EXTRAFLAGS)
EXTRAFLAGS = -pthread
SRCS = main.c init.c check_args.c routine.c monitor.c utils.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(NAME)

$(NAME) : $(OBJS)
	@echo "Compiling philo..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) $(ARGS)

clean:
	@echo "Cleaning up object files..."
	$(RM) $(OBJS)

fclean: clean
	@echo "Cleaning up compiled files..."
	$(RM) $(NAME)

re: fclean all

run:
	@read -p "Enter number of philosophers: " philo; \
	read -p "Enter time to die: " die; \
	read -p "Enter time to eat: " eat; \
	read -p "Enter time to sleep: " sleep; \
	read -p "Enter number of times to eat: " eat_count; \
	$(MAKE) re run_program ARGS="$$philo $$die $$eat $$sleep $$eat_count"

run_program:
	./$(NAME) $(ARGS)

run_valgrind:
	@read -p "Enter number of philosophers: " philo; \
	read -p "Enter time to die: " die; \
	read -p "Enter time to eat: " eat; \
	read -p "Enter time to sleep: " sleep; \
	read -p "Enter number of times to eat: " eat_count; \
	$(MAKE) re valgrind ARGS="$$philo $$die $$eat $$sleep $$eat_count"

.PHONY: all clean fclean re
.SILENT:
