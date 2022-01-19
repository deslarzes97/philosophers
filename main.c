/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desa <desa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:31:21 by desa              #+#    #+#             */
/*   Updated: 2022/01/19 16:17:41 by desa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death2(t_p *p)
{
	pthread_mutex_lock(&p->args.dead);
	if (p->args.stop)
	{
		pthread_mutex_unlock(&p->args.dead);
		return (1);
	}
	pthread_mutex_unlock(&p->args.dead);
	return (0);
}

static void	stop(t_p *p)
{
	int	i;

	i = -1;
	while (!check_death2(p))
		usleep(1);
	while (++i < p->args.nbr_philo)
		pthread_join(p->ph[i].thread_id, NULL);
	pthread_mutex_destroy(&p->args.print);
	i = -1;
	while (++i < p->args.nbr_philo)
		pthread_mutex_destroy(&p->ph[i].left_fork);
	if (p->args.stop == 2)
		printf("Each philosopher ate %i time(s)\n", p->args.nbr_to_eat);
	free(p->ph);
}

int	main(int argc, char **argv)
{
	t_p		p;

	if (!check_input(argc, argv, &p))
		return (printf("Invalid Arguments\n"));
	p.ph = malloc(sizeof(t_philo) * p.args.nbr_philo);
	if (!p.ph)
		exit (0);
	if (!ft_init(&p) || !threading(&p))
	{
		free(p.ph);
		return (0);
	}
	stop(&p);
}
