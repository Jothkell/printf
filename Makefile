#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 21:44:46 by jkellehe          #+#    #+#              #
#    Updated: 2018/09/19 18:08:08 by jkellehe         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = main.c mod.c

HEADER = printf.h

LIBFT = -L./libft -lft

LIB = libft

all:  $(NAME)

$(NAME):
	@gcc -g -c $(SRC) -I$(HEADER)
	@make -C $(LIB)
	@ar rc $(NAME) *.o ./libft/*.o
	@ranlib $(NAME)

clean:
	@rm -f *.o
	@make clean -C $(LIB)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB)

re: fclean all