/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:10:44 by abaldelo          #+#    #+#             */
/*   Updated: 2025/03/20 18:11:59 by abaldelo         ###   ########.fr       */
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
	// if (!parse_argv(argc, argv + 1))
	return (0);
}
