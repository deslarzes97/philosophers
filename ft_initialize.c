/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desa <desa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:16:57 by desa              #+#    #+#             */
/*   Updated: 2022/01/20 13:57:07 by desa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_mutex(t_p *ph)
{
	pthread_mutex_init(&ph->args.print, NULL);
	pthread_mutex_init(&ph->args.dead, NULL);
	pthread_mutex_init(&ph->args.eat, NULL);
	pthread_mutex_init(&ph->args.finish, NULL);
}

int	ft_init(t_p *p)
{
	int	i;

	i = 0;
	p->args.start = actual_time();
	p->args.stop = 0;
	p->args.nbr_philo_finish = 0;
	initialize_mutex(p);
	while (i < p->args.nbr_philo)
	{
		p->ph[i].id = i + 1;
		p->ph[i].ms_eat = p->args.start;
		p->ph[i].nbr_eat = 0;
		p->ph[i].finish = 0;
		p->ph[i].right_fork = NULL;
		pthread_mutex_init(&p->ph[i].left_fork, NULL);
		if (p->args.nbr_philo == 1)
			return (1);
		if (i == p->args.nbr_philo - 1)
			p->ph[i].right_fork = &p->ph[0].left_fork;
		else
			p->ph[i].right_fork = &p->ph[i + 1].left_fork;
		i++;
	}
	return (1);
}
