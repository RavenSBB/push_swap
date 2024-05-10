# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 12:02:46 by rboits-b          #+#    #+#              #
#    Updated: 2024/05/10 16:57:51 by rboits-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCL = .

SRC = ft_push_swap.c ft_push_commands.c ft_swap_commands.c ft_rotate_commands.c ft_reverse_rotate_commands.c ft_init.c ft_algorithm.c ft_utils.c ft_find_certain_nodes.c ft_rotate_to_top.c ft_cost_calc.c ft_free_stack.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g

all : $(NAME)

$(NAME): $(OBJS) $(INCL)
	 $(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCL) -c $< -o $@

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
