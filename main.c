/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desa <desa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:31:21 by desa              #+#    #+#             */
/*   Updated: 2022/01/18 10:06:56 by desa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_p		p;

	if (!check_input(argc, argv, &p))
		return (printf("Invalid Arguments\n"));
	p.ph = malloc(sizeof(t_philo) * p.args.nbr_philo);
	if (!p.ph)
		exit (0);
	if (!ft_init(&p) || threading(&p))
		return (printf("Error\n init\n"));

	return (0);
}
