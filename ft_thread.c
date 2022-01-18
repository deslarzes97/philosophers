/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeslarz <adeslarz@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:25:02 by desa              #+#    #+#             */
/*   Updated: 2022/01/18 16:27:24 by adeslarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		usleep(100);
	while (!check_death(philo, 0))
	{
		printf("id philo =%i\n", philo->id);
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
