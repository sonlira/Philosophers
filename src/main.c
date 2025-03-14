/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:44 by abaldelo          #+#    #+#             */
/*   Updated: 2025/03/14 13:54:40 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_number(char *str)
{
	
}

int	is_valid_args(int argc, char **argv)
{
	is_valid_number(argv[1]);
	
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 5 || argc != 6)
		return (1);
	if (!is_valid_args(argc, argv))
		return (1);
	return (0);
}
