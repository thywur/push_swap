# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 17:50:42 by alermolo          #+#    #+#              #
#    Updated: 2023/12/14 15:48:04 by alermolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		push_swap

SRCS = 		srcs/commands.c	\
			srcs/main.c		\
			srcs/push.c		\
			srcs/reverse_rotate.c	\
			srcs/rotate.c	\
			srcs/sort_three.c	\
			srcs/swap.c		\
			srcs/turk_sort.c		\
			srcs/free_and_exit.c	\
			srcs/ft_split.c	\
			srcs/ft_strlen.c	\
			srcs/parse_args.c	\
			srcs/push_to_top.c	\
			srcs/push_a_to_top.c	\
			srcs/biggest_smallest.c	\
			srcs/get_cost.c	\
			srcs/find_cheapest.c	\
			srcs/ft_lst.c	\
			srcs/ft_lst2.c	\
			srcs/ft_isdigit.c	\
			srcs/ft_min_max.c	\
			srcs/ft_atoi.c	\
			srcs/get_command.c	\

BSRCS =		bonus/checker.c	\
			srcs/commands.c	\
			srcs/push.c		\
			srcs/reverse_rotate.c	\
			srcs/rotate.c	\
			srcs/sort_three.c	\
			srcs/swap.c		\
			bonus/push_bonus.c		\
			bonus/reverse_rotate_bonus.c	\
			bonus/rotate_bonus.c	\
			bonus/swap_bonus.c		\
			srcs/turk_sort.c		\
			srcs/free_and_exit.c	\
			srcs/ft_split.c	\
			srcs/ft_strlen.c	\
			srcs/parse_args.c	\
			srcs/push_to_top.c	\
			srcs/push_a_to_top.c	\
			srcs/biggest_smallest.c	\
			srcs/get_cost.c	\
			srcs/find_cheapest.c	\
			srcs/ft_lst.c	\
			srcs/ft_lst2.c	\
			srcs/ft_isdigit.c	\
			srcs/ft_min_max.c	\
			srcs/ft_atoi.c	\
			srcs/get_command.c	\
			bonus/get_next_line.c	\
			bonus/get_next_line_utils.c	\

OBJS =		$(SRCS:.c=.o)

BOBJS =		$(BSRCS:.c=.o)

HEADER =	includes/push_swap.h

CC =		cc

CFLAGS =	-Wall -Werror -Wextra -fsanitize=address -g3

RM =		rm -rf

%.o :		%.c $(HEADER)
			$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

all:		$(NAME)

$(NAME): 	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:		$(BOBJS)
				$(CC) $(CFLAGS) $(BOBJS) -o checker

clean:
				$(RM) $(OBJS) $(BOBJS)

fclean:		clean
				$(RM) $(NAME) checker

re:			fclean all

.PHONY:		all clean fclean re bonus
