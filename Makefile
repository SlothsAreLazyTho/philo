# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cbijman <cbijman@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/22 18:31:30 by cbijman       #+#    #+#                  #
#    Updated: 2023/09/19 17:16:37 by cbijman       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = clang
NAME = philosophers

#Folders
SRC=src
BIN=bin

#Files
HEADER= ./include/philo.h
FILES=$(shell find $(SRC) -type f -name "*.c")
OBJ=${FILES:$(SRC)/%.c=$(BIN)/%.o}

default:
	$(CC) $(FILES) -I./include -o $(NAME)
	@./$(NAME)

.PHONY: default $(NAME)