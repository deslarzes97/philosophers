/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desa <desa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:06:07 by adeslarz          #+#    #+#             */
/*   Updated: 2022/01/20 13:25:58 by desa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->philo_args->dead);
	if (i)
		philo->philo_args->stop = i;
	if (philo->philo_args->stop)
	{
		pthread_mutex_unlock(&philo->philo_args->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->philo_args->dead);
	return (0);
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
	while ((actual_time() - start_time) < time_in_ms)
		ft_usleep(time_in_ms / 10);
}
