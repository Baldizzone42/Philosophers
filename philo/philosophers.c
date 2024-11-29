/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:38 by jormoral          #+#    #+#             */
/*   Updated: 2024/11/19 20:37:43 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg(char **argv)
{
	if ((ft_atol(argv[1]) > 200) || ft_atol(argv[1]) <= 0)
		return (ft_error("Number of philosophers"));
	if (ft_atol(argv[2]) <= 0)
		return (ft_error("Time to die"));
	if (ft_atol(argv[3]) <= 0)
		return (ft_error("Time to eat"));
	if (ft_atol(argv[4]) <= 0)
		return (ft_error("Time to sleep"));
	if (argv[5])
		if (ft_atol(argv[5]) <= 0)
			return (ft_error("Number of meals"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	philos[200];
	t_prog	program;

	if (argc != 5 && argc != 6)
		return (ft_error("Number of arguments"));
	if (check_arg(argv))
		return (1);
	initialize_program(&program, philos, argv);
	return (0);
}
