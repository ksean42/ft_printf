# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksean <ksean@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 20:13:57 by ksean             #+#    #+#              #
#    Updated: 2020/03/15 17:18:16 by ksean            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MAKE V2

PATH = srcs/

SRC =	ft_printf.c dec_to_hex.c

OBJ = $(SRC:.c=.o)
LIB = libftprintf.a
LIB_PATH := ./libft/

FLAGS = -Wall -Wextra -Werror

NAME = ft_printf

all: $(NAME) $(LIB) $(OBJ)

test: $(OBJ) $(LIB)
	gcc  -g $(SRC) main_test.c -o $(NAME) $(LIB_PATH)$(LIB)

$(NAME): $(OBJ) $(LIB)
		/usr/bin/ar rc $(LIB) $(OBJ) $(LIB_PATH)*.o
		ranlib $(LIB)

$(LIB):
	make -C $(LIB_PATH)

$(OBJ): %.o: %.c
		gcc $(FLAGS) -g -I ft_printf.h -I $(LIB_PATH) -o $@ -c $^

clean:
		rm -rf $(OBJ)
		make clean -C $(LIB_PATH)

fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf $(LIB)
	/bin/rm -rf $(LIB_PATH)*.o

re: fclean all