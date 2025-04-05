/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:56:21 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/05 16:32:46 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_error(const char *s)
{
	size_t	i;

	i = 0;
	write(2, "Error: ", 8);
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

void	destroy_mutexes(t_mtx *mtx, size_t size)
{
	size_t	i;

	if (size <= 0 || !mtx)
		return ;
	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&mtx[i]);
		i++;
	}
}

long	get_timestamp_ms(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	safe_sleep(t_philo *philo, long time)
{
	long	start;

	start = get_timestamp_ms();
	while (!check_death(philo) && get_timestamp_ms() - start < time)
		usleep(100);
}

int	check_death(t_philo *philo)
{
	int	is_dead;

	pthread_mutex_lock(&philo->config->dead_look);
	is_dead = philo->config->is_dead;
	pthread_mutex_unlock(&philo->config->dead_look);
	return (is_dead);
}
