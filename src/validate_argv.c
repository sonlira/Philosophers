/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:58:13 by abaldelo          #+#    #+#             */
/*   Updated: 2025/03/20 18:21:25 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			return (0);
		if (!is_greater_than_zero(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
