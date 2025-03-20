/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:44 by abaldelo          #+#    #+#             */
/*   Updated: 2025/03/20 21:58:34 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("numero de argumentos no valido: %d\n",argc);
		return (1);
	}
	if (!is_valid_argv(argv + 1))
	{
		printf("argumentos no validos\n");
		return (1);
	}
	// parse_argv(&table, argc - 1, argv + 1);
	// int i = 0;
	// while (i < table.philos[0].num_philos)
	// {
	// 	printf("id: %d\n", table.philos[i].id);
	// 	i++;
	// }
	return (0);
}
