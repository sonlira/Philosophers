/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:44 by abaldelo          #+#    #+#             */
/*   Updated: 2025/03/21 20:06:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	// t_taple			table;
	// t_philo			philos[MAX];
	// pthread_mutex_t	forks[MAX];

	if (argc < 5 || argc > 6)
		return (write_error("Number of arguments not valid"), 1);
	if (!is_valid_argv(argv + 1))
		return (1);
	return (0);
}
