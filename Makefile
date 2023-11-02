# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cbijman <cbijman@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/22 18:31:30 by cbijman       #+#    #+#                  #
#    Updated: 2023/11/02 13:02:17 by cbijman       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS =  -g -fsanitize=address #-Wall -Wextra -Werror
NAME = philosophers

#Folders
OBJ_FOLDER=bin

#Files
HEADER= ./include/philo.h
SRC=$(shell find ./src -type f -name "*.c")
OBJ=${SRC:./src/%.c=$(OBJ_FOLDER)/%.o}

all: $(NAME)

$(OBJ_FOLDER)/%.o: ./src/%.c | bin
	$(CC) $(CFLAGS) -I./include -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -I./include -o $(NAME)

debug: clean $(OBJ)
	$(CC) -g -fsanitize=thread $(OBJ) -I./include -o $(NAME)
	#valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME)

bin:
	mkdir -p $(OBJ_FOLDER)

clean:
	rm -rf $(OBJ_FOLDER)

fclean:
	rm -rf $(NAME) $(OBJ_FOLDER)

re: fclean all

.PHONY: default all debug clean fclean re