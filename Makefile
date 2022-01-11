# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: desa <desa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 22:22:50 by desa              #+#    #+#              #
#    Updated: 2022/01/10 23:11:58 by desa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c\
		ft_utils.c\

NAME		= philo

CFLAGS 		= -g -fsanitize=address -Wall -Wextra -Werror

OBJS 		= ${SRCS:.c=.o}

RM 			= rm -f

CC			= gcc

all: ${NAME}

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
			$(CC) -c $(CFLAGS) $< -o $@

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re

#-g -fsanitize=address