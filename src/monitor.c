/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:51:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/10 13:06:27 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	release_forks(t_philo *philo)
{
	if (!philo)
		return ;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

static int	loop_to_check_death(t_config *cfg)
{
	int		i;
	long	now;
	long	time_since_meal;

	i = 0;
	while (i < cfg->number_philos)
	{
		now = get_timestamp_ms();
		pthread_mutex_lock(&cfg->meal_look);
		time_since_meal = now - cfg->philos[i].last_meal;
		pthread_mutex_unlock(&cfg->meal_look);
		if (time_since_meal > cfg->time_to_die)
		{
			pthread_mutex_lock(&cfg->dead_look);
			cfg->is_dead = 1;
			pthread_mutex_unlock(&cfg->dead_look);
			printf("%ld %d is died\n"\
				, now - cfg->philos[i].start_time, cfg->philos[i].id);
			return (-1);
		}
		i++;
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_config	*cfg;

	cfg = (t_config *)arg;
	while (1)
	{
		if (loop_to_check_death(cfg) != 0)
			return (NULL);
		pthread_mutex_lock(&cfg->full_lock);
		if (cfg->must_eat != -1 && cfg->full_count >= cfg->number_philos)
		{
			pthread_mutex_lock(&cfg->dead_look);
			cfg->is_dead = 1;
			pthread_mutex_unlock(&cfg->dead_look);
			pthread_mutex_unlock(&cfg->full_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&cfg->full_lock);
		usleep(1000);
	}
	return (NULL);
}
