/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_think_eat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desa <desa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:42:45 by desa              #+#    #+#             */
/*   Updated: 2022/01/20 14:12:32 by desa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_activity(char *str, t_philo *philo)
{
	long int	time;

	time = -1;
	time = actual_time() - philo->philo_args->start;
	if (!check_death(philo, 0))
	{
		printf("%ld", time);
		printf(": philo %d %s", philo->id, str);
	}
}

void	sleep_and_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_args->print);
	write_activity("is sleeping\n", philo);
	pthread_mutex_unlock(&philo->philo_args->print);
	ft_usleep(philo->philo_args->time_to_sleep);
	pthread_mutex_lock(&philo->philo_args->print);
	write_activity("is thinking\n", philo);
	pthread_mutex_unlock(&philo->philo_args->print);
}

void	take_fork_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->philo_args->print);
	write_activity("has take a fork\n", philo);
	pthread_mutex_unlock(&philo->philo_args->print);
	/*if (!philo->right_fork)
	{
		ft_usleep(philo->philo_args->time_to_die * 2);
		return ;
	}*/
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->philo_args->print);
	write_activity("has take a fork\n", philo);
	pthread_mutex_unlock(&philo->philo_args->print);
	pthread_mutex_lock(&philo->philo_args->print);
	write_activity("is eating\n", philo);
	pthread_mutex_lock(&philo->philo_args->eat);
	philo->ms_eat = actual_time();
	pthread_mutex_unlock(&philo->philo_args->eat);
	pthread_mutex_unlock(&philo->philo_args->print);
	ft_usleep(philo->philo_args->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	sleep_and_think(philo);
}
