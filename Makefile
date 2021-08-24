# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 15:57:39 by hyunwkim          #+#    #+#              #
#    Updated: 2021/08/24 16:08:15 by hyunwkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = node_value_swap.c ft_atoi.c ft_putchar.c ft_split.c

OB= $(SRC:.c=.o)

SRCS_DIR = srcs
#BONUS_DIR = bonus

SRCS        = $(addprefix $(SRCS_DIR)/, $(SRC))
OBJS        = $(addprefix $(SRCS_DIR)/, $(OB))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus : $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean :
	rm -f $(OBJS)
	#rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)
	#rm -f $(NAME) $(NAME_BONUS)

re : fclean all
