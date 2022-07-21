# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivasile <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 15:24:47 by nivasile          #+#    #+#              #
#    Updated: 2022/07/12 19:20:54 by nivasile         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = ./srcs/

INC_SOURCE = ./includes/

SRC = $(SRC_PATH)ft_putchar.c $(SRC_PATH)ft_putstr.c $(SRC_PATH)ft_strcmp.c \
	  $(SRC_PATH)ft_swap.c $(SRC_PATH)ft_strlen.c

OBJ = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all: $(NAME)

.PHONY: clean fclean re

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC) -I $(INC_SOURCE)$(wildcard *.h)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(wildcard *.o)

fclean: clean
	rm -f $(NAME)

re: fclean all
