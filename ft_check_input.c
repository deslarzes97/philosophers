/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desa <desa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:27:14 by desa              #+#    #+#             */
/*   Updated: 2022/01/13 15:36:44 by desa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_is_numeric(char **argv, int j)
{
	int	i;

	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_input(int argc, char **argv, t_p *p)
{
	if ((argc == 5 || argc == 6) && check_is_numeric(argv, 1) == 1)
	{
			p->args.nbr_philo = ft_atoi(argv[1]);
			p->args.time_to_die = ft_atoi(argv[2]);
			p->args.time_to_eat = ft_atoi(argv[3]);
			p->args.time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			p->args.nbr_to_eat = ft_atoi(argv[5]);
		return (1);
	}
	else
		return (0);
}
