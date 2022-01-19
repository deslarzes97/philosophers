/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desa <desa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:25:02 by desa              #+#    #+#             */
/*   Updated: 2022/01/19 14:26:25 by desa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_is_dead(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	usleep(philo->philo_args->time_to_die);
	pthread_mutex_lock(&philo->philo_args->eat);
	pthread_mutex_lock(&philo->philo_args->finish);
	if (!check_death(philo, 0) && !philo->finish && ((actual_time() - philo->ms_eat) \
		>= (long)(philo->philo_args->time_to_die)))
	{
		pthread_mutex_unlock(&philo->philo_args->eat);
		pthread_mutex_unlock(&philo->philo_args->finish);
		pthread_mutex_lock(&philo->philo_args->print);
		write_activity("died\n", philo);
		pthread_mutex_unlock(&philo->philo_args->print);
		check_death(philo, 1);
	}
	pthread_mutex_unlock(&philo->philo_args->eat);
	pthread_mutex_unlock(&philo->philo_args->finish);
	return (NULL);
}

void	*thread(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!check_death(philo, 0))
	{
		pthread_create(&philo->thread_dead_id, NULL, thread_is_dead, data);
		take_fork_eating(philo);
		pthread_detach(philo->thread_dead_id);
	}
	return (NULL);
}

int	threading(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->args.nbr_philo)
	{
		p->ph[i].philo_args = &p->args;
		pthread_create(&p->ph[i].thread_id, NULL, thread, &p->ph[i]);
		i++;
	}
	return (1);
}
