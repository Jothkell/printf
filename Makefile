#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 21:44:46 by jkellehe          #+#    #+#              #
#    Updated: 2018/08/30 11:37:03 by jkellehe         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = getnextline

SRC = main.c mod.c

HEADER = printf.h

LIBFT = -L./libft -lft

LIB = libft

all: $(NAME) $(LIB) $(MINIL)

$(NAME):
	gcc -g -c -Wall -Wextra -Werror $(SRC) -I$(HEADER)
	gcc -o $(NAME) *.o $(LIBFT)

$(LIB):
	@make -C $(LIB)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all