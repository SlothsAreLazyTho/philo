# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cbijman <cbijman@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/22 18:31:30 by cbijman       #+#    #+#                  #
#    Updated: 2023/05/23 20:12:59 by cbijman       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = clang
NAME = philosophers

#Folders
SRC=src
BIN=bin

#Files
HEADER=./include/philo.h
FILES=$(shell find $(SRC) -type f -name "*.c")
OBJ=${FILES:$(SRC)/%.c=$(BIN)/%.o}

all: $(NAME) run

$(BIN)/%.o: $(SRC)/%.c | $(BIN)
	$(CC) -Iinclude -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) -Iinclude $(OBJ) -pthread -o $(NAME)

$(BIN):
	mkdir -p bin

run:
	clear && ./$(NAME)	

clean:
	rm -rf $(OBJ) $(BIN)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all run clean fclean re
	