# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cbijman <cbijman@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/26 13:27:47 by cbijman       #+#    #+#                  #
#    Updated: 2022/11/02 16:11:02 by cbijman       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
AR = ar -rcs
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
HEADERFILES = ft_printf.h

SRCS = 	ft_printf.c \
		ft_print_ptr.c \
		ft_print_hex.c \
		ft_print_utils.c \

OBJS = ${SRCS:%.c=%.o}

.c.o: $(SRCS) $(HEADERFILES)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re