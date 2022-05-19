# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samin <samin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 15:07:45 by samin             #+#    #+#              #
#    Updated: 2021/09/30 20:13:04 by samin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= main.c action.c init.c monitor.c util.c util2.c

NAME	= philo

OBJS	= $(SRCS:.c=.o)

rm		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all	:	$(NAME)

$(NAME)	:	
			$(CC) $(SRCS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
