/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeslarz <adeslarz@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:42:15 by desa              #+#    #+#             */
/*   Updated: 2022/01/18 16:26:26 by adeslarz         ###   ########.fr       */
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

typedef struct s_args
{
	int			nbr_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_to_eat;
	int			dead;
	long int	start;
	long int	stop;
}				t_args;

typedef struct s_philo
{
	int				id;
	long int		ms_eat;
	unsigned int	nbr_eat;
	pthread_t		thread_id;
	int				left_f;
	int				right_f;
	int				fork_id;
	t_args			*philo_args;
}				t_philo;

typedef struct s_p
{
	t_philo		*ph;
	t_args		args;
}				t_p;

typedef struct s_time
{
	long int		tv_sec;
	int				tv_usec;
	unsigned int	timestamp_in_ms;
	unsigned int	prog_start;
}	t_time;

/* Fonctions */

// ft_utils.c
int			ft_atoi(const char *str);
long int	actual_time(void);

// ft_utils_philo.c
int			check_death(t_philo *philo, int i);

// ft_check_input.c
int			check_input(int argc, char **argv, t_p *p);

// ft_initialize.c
int			ft_init(t_p *p);

// ft_thread.c
int			threading(t_p *p);
void		*thread(void *data);

#endif
