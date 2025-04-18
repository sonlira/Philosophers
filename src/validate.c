/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:58:13 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/10 13:06:12 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	message(int code)
{
	if (code == 0)
		write_error("Number of arguments not valid");
	else if (code == 1)
		write_error("Number of philosophers not valid");
	else if (code == 2)
		write_error("Invalid time to die");
	else if (code == 3)
		write_error("Invalid time to eat");
	else if (code == 4)
		write_error("Invalid time to sleep");
	else if (code == 5)
		write_error("Invalid number of times each philosopher must eat");
}

static int	ft_atoi(const char *str)
{
	long		num;
	int			sign;
	size_t		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return ((int)(num * sign));
}

static int	check_the_values(int ac, t_config *config)
{
	if (config->number_philos <= 0 || config->number_philos > MAX_PHILOS)
		return (message(1), -1);
	if (config->time_to_die <= 0)
		return (message(2), -1);
	if (config->time_to_eat <= 0)
		return (message(3), -1);
	if (config->time_to_sleep <= 0)
		return (message(4), -1);
	if (ac == 6 && config->must_eat <= 0)
		return (message(5), -1);
	return (0);
}

static void	convert_the_arguments(int ac, char **av, t_config *config)
{
	config->number_philos = ft_atoi(av[1]);
	config->time_to_die = ft_atoi(av[2]);
	config->time_to_eat = ft_atoi(av[3]);
	config->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		config->must_eat = ft_atoi(av[5]);
	else
		config->must_eat = -1;
}

int	parse_args(int ac, char **av, t_config *config)
{
	if (ac != 5 && ac != 6)
		return (message(0), -1);
	convert_the_arguments(ac, av, config);
	if (check_the_values(ac, config) != 0)
		return (-1);
	return (0);
}
