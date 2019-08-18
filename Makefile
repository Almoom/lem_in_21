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
SRC = main.c

make:
	@$(CC) -g -o $(NAME) $(SRC) lem-in.c list_const.c list_val.c check_comment_and_realnum.c check_xy_and_edge.c splits.c duplicate.c /Users/ljalikak/Documents/push_swap_21/libft/libft.a

clean:
	@rm -f /Users/ljalikak/Documents/push_swap_21/libft/*.o

fclean: clean
	rm -f $(NAME)

re: fclean make
