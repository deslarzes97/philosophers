/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desa <desa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:42:15 by desa              #+#    #+#             */
/*   Updated: 2022/01/20 13:26:04 by desa             ###   ########.fr       */
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

/* Structures */

typedef struct s_args
{
	int						nbr_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						nbr_to_eat;
	long int				start;
	pthread_mutex_t			print;
	pthread_mutex_t			dead;
	pthread_mutex_t			eat;
	pthread_mutex_t			finish;
	long int				stop;
	int						nbr_philo_finish;
}							t_args;

typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	pthread_t				thread_dead_id;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			left_fork;
	long int				ms_eat;
	unsigned int			nbr_eat;
	int						finish;
	t_args					*philo_args;
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

// ft_sleep_think_eat.c
void		write_activity(char *str, t_philo *philo);
void		sleep_and_think(t_philo *philo);
void		take_fork_eating(t_philo *philo);
void		ft_usleep(long int time_in_ms);
#endif
