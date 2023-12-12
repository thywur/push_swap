# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 17:50:42 by alermolo          #+#    #+#              #
#    Updated: 2023/12/12 16:10:57 by alermolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		push_swap

SRCS = 		commands.c	\
			libft.c		\
			main.c		\
			push.c		\
			reverse_rotate.c	\
			rotate.c	\
			sort_three.c	\
			swap.c		\
			turk_sort.c		\
			free_and_exit.c	\
			ft_split.c	\
			ft_strlen.c	\
			parse_args.c	\

OBJS =		$(SRCS:.c=.o)

HEADER =	push_swap.h

CC =		cc

CFLAGS =	-Wall -Werror -Wextra -fsanitize=address -g3

RM =		rm -rf

%.o :		%.c $(HEADER)
			$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

all:		$(NAME)

$(NAME): 	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS) $(BOBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
