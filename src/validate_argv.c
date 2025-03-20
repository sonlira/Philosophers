/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:58:13 by abaldelo          #+#    #+#             */
/*   Updated: 2025/03/20 22:34:05 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	message(int code)
{
	if (code == 0)
		write_error("Number of philosophers not valid");
	else if (code == 1)
		write_error("Invalid time to die");
	else if (code == 2)
		write_error("Invalid time to eat");
	else if (code == 3)
		write_error("Invalid time to sleep");
	else if (code == 4)
		write_error("Invalid number of times each philosopher must eat");
}

static int	is_a_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}


static int	is_greater_than_zero(char *str)
{
	return (ft_atoi64(str) > 0);
}

int	is_valid_argv(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{

		if (!is_a_valid_number(argv[i]))
			return (message(i), 0);
		if (!is_greater_than_zero(argv[i]))
			return (message(i), 0);
		i++;
	}
	if (ft_atoi64(argv[0]) < MIN || ft_atoi64(argv[0]) > MAX)
		return (message(0), 0);
	return (1);
}
