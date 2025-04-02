/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:37 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/02 21:14:28 by abaldelo         ###   ########.fr       */
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

// enum
// {
// 	MAX = 300,
// 	MIN = 6,
// 	OK = 1,
// 	KO = 0,
// };

// typedef struct s_philo
// {
// 	int					id;
// 	uint64_t			last_meal;
// 	uint64_t			time_to_die;
// 	uint64_t			time_to_eat;
// 	uint64_t			time_to_sleep;
// 	uint64_t			start_time;
// 	int					num_times_to_eat;
// 	int					num_philos;
// 	pthread_mutex_t		*r_fork;
// 	pthread_mutex_t		*l_fork;
// }	t_philo;

// typedef struct s_table
// {

// 	t_philo	*philos;
// }	t_taple;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	t_mtx			*left_fork;
	t_mtx			*right_fork;
	long			last_meal;
	int				meals_eaten;
	struct s_config	*config;
}	t_philo;

typedef struct s_config
{
	int		number_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
	long	start_time;
	t_mtx	*forks;
	t_philo	*philos;
}	t_config;


// utils.c
int		ft_atoi(const char *str);
void	write_error(const char *s);
void	destroy_mutexes(t_mtx *mtx, size_t size);
long	get_timestamp_ms(void);
// validate.c
int		parse_args(int ac, char **av, t_config *config);
// init.c
int		init_all(t_config *config);

#endif