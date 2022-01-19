# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: desa <desa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 22:22:50 by desa              #+#    #+#              #
#    Updated: 2022/01/19 14:51:02 by desa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c\
		ft_utils.c\
		ft_check_input.c\
		ft_initialize.c\
		ft_thread.c\
		ft_utils_philo.c\
		ft_sleep_think_eat.c\

NAME		= philo

CFLAGS 		= -g -Wall -Wextra -Werror

OBJS 		= ${SRCS:.c=.o}

RM 			= rm -f

CC			= gcc

all: ${NAME}

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lpthread 

%.o : %.c
			$(CC) -c $(CFLAGS) $< -o $@

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re

#-g -fsanitize=address
#-lpthread