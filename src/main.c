/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:44 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/03 18:33:36 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_threads(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->number_philos)
	{
		if (pthread_create(&config->philos[i].thread, NULL, philo_routine, &config->philos[i]) != 0)
			return (write_error("Al crear los hilos"), -1);
		i++;
	}
	if (pthread_create(&config->monitor, NULL, monitor, config) != 0)
		return (write_error("Al crear los hilos"), -1);
	return (0);
}

int	join_threads(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->number_philos)
	{
		if (pthread_join(config->philos[i].thread, NULL) != 0)
			return (write_error("Al unir los hilos"), -1);
		i++;
	}
	if (pthread_join(config->monitor, NULL) != 0)
		return (write_error("Al unir los hilos"), -1);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo		philos[MAX_PHILOS];
	t_mtx		forks[MAX_PHILOS];
	t_config	config;

	config.philos = philos;
	config.forks = forks;
	if (parse_args(ac, av, &config) != 0)
		return (1);
	if (init_all(&config) != 0)
		return (1);
	if (start_threads(&config) != 0)
		return (1);
	if (join_threads(&config) != 0)
		return (1);
	return (0);
}
