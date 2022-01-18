/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desa <desa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:25:02 by desa              #+#    #+#             */
/*   Updated: 2022/01/13 20:55:19 by desa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	printf("Thread active\n");
}

int threading(t_p *p)
{
	int i;

	i = 0;
	while (i < p->args.nbr_philo)
	{
		p->ph[i].philo_args = &p->args;
		pthread_create(&p->ph->thread_death_id, NULL, thread, &p->ph[i]);
		i++;
	}
	return (1);
}
