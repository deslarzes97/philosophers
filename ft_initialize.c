/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeslarz <adeslarz@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:16:57 by desa              #+#    #+#             */
/*   Updated: 2022/01/18 11:58:16 by adeslarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init(t_p *p)
{
	int	i;

	i = 0;
	p->args.start = actual_time();
	p->args.stop = 0;
	while (i < p->args.nbr_philo)
	{
		p->ph[i].id = i;
		p->ph[i].ms_eat = p->args.start;
		p->ph[i].nbr_eat = 0;
		if (p->args.nbr_philo == 1)
			return (1);
		i++;
	}
	return (1);
}
