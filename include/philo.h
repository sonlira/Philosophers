/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:37 by abaldelo          #+#    #+#             */
/*   Updated: 2025/03/20 22:25:07 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdint.h>

enum
{
	MAX = 300,
	MIN = 6,
	OK = 1,
	KO = 0,
};

typedef struct s_philo
{
	int					id;
	uint64_t			last_meal;
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	uint64_t			start_time;
	int					num_times_to_eat;
	int					num_philos;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
}	t_philo;

typedef struct s_table
{

	t_philo	*philos;
}	t_taple;

uint64_t	ft_atoi64(const char *str);
void		write_error(char *s);
int			is_valid_argv(char **argv);
void		parse_argv(t_taple *table, int argc, char **argv);
#endif