# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samin <samin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 15:07:45 by samin             #+#    #+#              #
#    Updated: 2021/07/23 13:55:46 by samin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= libft/libft.a  philosophers.c action.c init.c monitor.c util.c 

NAME	= philo

OBJS	= $(SRCS:.c=.o)

rm		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g

all	:	$(NAME)

$(NAME)	:	#$(OBJS)
			$(CC) $(SRCS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
