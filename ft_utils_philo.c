/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desa <desa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:06:07 by adeslarz          #+#    #+#             */
/*   Updated: 2022/01/19 15:24:23 by desa             ###   ########.fr       */
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