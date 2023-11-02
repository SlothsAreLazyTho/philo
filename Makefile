# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cbijman <cbijman@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/22 18:31:30 by cbijman       #+#    #+#                  #
#    Updated: 2023/11/02 13:26:36 by cbijman       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Variables
NAME = philosophers
CC = clang
RM = rm -rf

#Colours
RESET = \033[0m
RED = \033[31;01m
GREEN = \033[0;92m

#Folders
BIN := bin
INCLUDE = include
FOLDER = src

#Source files
HEADERS = $(INCLUDE)/philo.h
FILES = actions.c cleanup.c init.c logger.c main.c time_utils.c utils.c validate.c

#Source
SRC = ${addprefix $(FOLDER)/, $(FILES)}
OBJ = ${SRC:$(FOLDER)/%.c=$(BIN)/%.o}

# Compiler settings
CFLAGS = -Wall -Wextra -Werror
IFLAG = -I$(INCLUDE)

# Operations.
all: $(NAME)

$(BIN)/%.o: $(FOLDER)/%.c | $(BIN)
	@$(CC) $(CFLAGS) $(IFLAG) -c $< -o $@
	@echo "$(GREEN)Compiling: $(RESET)$(notdir $<)"

$(NAME): $(OBJ) $(HEADERS) 
	@$(CC) $(CFLAGS) $(OBJ) $(IFLAG) -o $(NAME)
	@echo "$(GREEN)Compiling: $(RESET)$(NAME)"

$(BIN):
	@mkdir $(BIN)

clean:
	@$(RM) $(OBJ) $(BIN)
	@echo "$(RED)Cleaning!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Cleaning!$(RESET)"

re: fclean all

.PHONY: all clean fclean re