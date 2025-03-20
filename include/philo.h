/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:37 by abaldelo          #+#    #+#             */
/*   Updated: 2025/03/20 18:11:44 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_philo
{
	int			id;
	uint64_t	last_meal;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	uint64_t	start_time;
	int			num_philos;
	int			num_times_to_eat;
}	t_philo;

uint64_t	ft_atoi64(const char *str);
int			is_valid_argv(char **argv);
int			parse_argv(int argc, char **argv);
#endif