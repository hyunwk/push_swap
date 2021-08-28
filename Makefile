# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 15:57:39 by hyunwkim          #+#    #+#              #
#    Updated: 2021/08/28 00:46:47 by hyunwkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 
CC = gcc
CFLAGS = -g3 
SRCS_DIR = srcs

SRC = main.c sort.c basic_command.c command.c ft_atoi.c ft_putchar.c ft_split.c 
OBJ = $(SRC:.c=.o)

SRCS        = $(addprefix $(SRCS_DIR)/, $(SRC))
OBJS        = $(addprefix $(SRCS_DIR)/, $(OBJ))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
