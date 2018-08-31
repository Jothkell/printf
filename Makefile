#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 21:44:46 by jkellehe          #+#    #+#              #
#    Updated: 2018/08/30 12:54:11 by jkellehe         ###   ########.fr        #
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
	@cp libft/libft.a $(NAME)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

clean:
	@rm -f *.o
	@make clean -C $(LIB)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB)

re: fclean all