# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksean <ksean@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 20:13:57 by ksean             #+#    #+#              #
#    Updated: 2020/04/19 05:00:06 by ksean            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MAKE V2

PATH = ./src/

SRC =	$(addprefix $(PATH), ft_printf.c parser.c manage_p.c manage_d.c \
		manage_u.c manage_o.c manage_x.c manage_csper.c manage_buffer.c utils.c)

OBJ = $(SRC:.c=.o)
INC = ./include/
NAME = libftprintf.a
LIBFT = ./libft/libft.a
LIB_PATH := ./libft/

FLAGS = -Wall -Wextra -Werror

BIN = ft_printf

all:	$(NAME)

test:	$(BIN)

$(BIN):	$(LIBFT)
		@gcc -g $(SRC) main_test.c -o $(BIN) $(LIB_PATH)libft.a
		./$(BIN)

$(NAME): $(LIBFT)  $(OBJ)
		@/usr/bin/ar rcs $(NAME) $(LIB_PATH)*.o $(OBJ)
		@/usr/bin/ranlib $(NAME)
		@echo "\033[32mCompiled: $@\033[0m"

$(LIBFT):
		@make -C $(LIB_PATH)

$(OBJ): %.o: %.c
		@/usr/bin/gcc $(FLAGS) -I $(INC) -I $(LIB_PATH) -o $@ -c $^

clean:
		@/bin/rm -rf $(OBJ)
		@make clean -C $(LIB_PATH)
		@echo "\033[32mCleaned\033[0m"

fclean: clean
		@/bin/rm -rf $(NAME)
		@make fclean -C $(LIB_PATH)
		@echo "\033[32mCleaned\033[0m"

re:		fclean all