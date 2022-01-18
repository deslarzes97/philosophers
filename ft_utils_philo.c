/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeslarz <adeslarz@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:06:07 by adeslarz          #+#    #+#             */
/*   Updated: 2022/01/18 16:25:09 by adeslarz         ###   ########.fr       */
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
