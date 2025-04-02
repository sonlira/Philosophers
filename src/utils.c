/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:56:21 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/02 21:16:04 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
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
