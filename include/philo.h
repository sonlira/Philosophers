/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:37 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/10 13:06:32 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef MAX_PHILOS
#  define MAX_PHILOS 300
# endif

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef pthread_mutex_t	t_mtx;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	t_mtx			*left_fork;
	t_mtx			*right_fork;
	long			last_meal;
	long			start_time;
	int				meals_eaten;
	struct s_config	*config;
}	t_philo;

typedef struct s_config
{
	int			number_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	int			is_dead;
	int			full_count;
	t_mtx		meal_look;
	t_mtx		dead_look;
	t_mtx		full_lock;
	t_mtx		*forks;
	t_philo		*philos;
	pthread_t	monitor;
}	t_config;

// utils.c
int		check_death(t_philo *philo);
void	write_error(const char *s);
void	destroy_mutexes(t_mtx *mtx, size_t size);
long	get_timestamp_ms(void);
void	safe_sleep(t_philo *philo, long time);
// validate.c
int		parse_args(int ac, char **av, t_config *config);
// init.c
int		init_all(t_config *config);
// routine.c
void	*philo_routine(void *arg);
// monitor.c
void	*monitor(void *arg);
void	release_forks(t_philo *philo);

#endif