# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rboits-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 12:02:46 by rboits-b          #+#    #+#              #
#    Updated: 2024/05/03 18:25:22 by rboits-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCL = .

SRC = ft_initialize.c ft_push_swap.c ft_push_swap_utils.c utils.c ft_push_commands.c ft_swap_commands.c ft_rotate_commands.c ft_reverse_rotate_commands.c free.c

#SRC = ft_initialize.c ft_push_commands.c ft_push_swap.c ft_push_swap_utils.c\
	  ft_reverse_rotate_commands.c ft_rotate_commands.c\
	  utils.c ft_sort_stacks.c ft_swap_commands.c

OBJS = $(SRC:.c=.o)

CC = cc
#CFLAGS = -Wall -Wextra -Werror -g
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
