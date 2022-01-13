/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desa <desa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:25:02 by desa              #+#    #+#             */
/*   Updated: 2022/01/13 17:37:39 by desa             ###   ########.fr       */
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
		pthread_create(&p->ph->thread_death_id, NULL, thread, &p->ph[i]);
		i++;
	}
}