# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cbijman <cbijman@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/22 18:31:30 by cbijman       #+#    #+#                  #
#    Updated: 2023/10/03 14:06:46 by cbijman       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -g#-Wall -Wextra -Werror
NAME = philosophers

#Folders
SRC=src
BIN=bin

#Files
HEADER= ./include/philo.h
FILES=$(shell find $(SRC) -type f -name "*.c")
OBJ=${FILES:$(SRC)/%.c=$(BIN)/%.o}

default:
	$(CC) $(CFLAGS) $(FILES) -I./include -o $(NAME)

.PHONY: default $(NAME)