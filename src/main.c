/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:44 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/02 20:35:13 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo		philos[MAX_PHILOS];
	t_mtx		forks[MAX_PHILOS];
	t_config	config;

	if (parse_args(ac, av, &config) != 0)
		return (1);
	config.philos = philos;
	config.forks = forks;
	if (init_all(&config) != 0)
		return (1);
	return (0);
}
