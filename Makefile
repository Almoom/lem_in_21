# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 13:04:11 by ljalikak          #+#    #+#              #
#    Updated: 2019/04/04 13:04:14 by ljalikak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = lem-in
SRC = lem-in.c

make:
	@$(CC) -o $(NAME) $(SRC) /Users/ljalikak/Documents/push_swap_21/libft/libft.a

clean:
	@rm -f /Users/ljalikak/Documents/push_swap_21/libft/*.o

fclean: clean
	rm -f $(NAME)

re: fclean make
