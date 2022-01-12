/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desa <desa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:42:15 by desa              #+#    #+#             */
/*   Updated: 2022/01/12 17:24:28 by desa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Librairies */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

/* terminal color */

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define DEFAULT "\033[0m"

/* Structures */

typedef struct	s_args
{
	int		nbr_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nbr_to_eat;
}				t_args;

typedef struct	s_philo
{
	int			id;
	pthread_t	thread_id;
	t_args		philo_args;
}				t_philo;

typedef struct	s_p
{
	t_philo		*ph;
	t_args		args;
}				t_p;


/* Fonctions */
int		ft_atoi(const char *str);
int		check_input(int argc, char **argv, t_p *p);

#endif
