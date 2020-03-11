# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksean <ksean@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 20:13:57 by ksean             #+#    #+#              #
#    Updated: 2020/03/10 18:18:59 by ksean            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH = srcs/

SRC =	ft_printf.c dec_to_hex.c

OBJ = $(SRC:.c=.o)
LIB = libftprintf.a
LIB_PATH := ./libft/

FLAGS = -Wall -Wextra -Werror -g

NAME = ft_printf

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
		gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)$(LIB)

$(LIB):
		make -C $(LIB_PATH)

$(OBJ): %.o: %.c
		gcc $(FLAGS) -I ft_printf.h -I $(LIB_PATH) -o $@ -c $^

clean:
		rm -rf $(OBJ)
		make clean -C $(LIB_PATH)

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -rf $(NAME)

re: fclean all