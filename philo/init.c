/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:23:45 by jormoral          #+#    #+#             */
/*   Updated: 2024/11/20 10:56:26 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize_threads(t_prog *program, pthread_mutex_t *forks,
	t_philo *philos)
{
	int	i;

	i = 0;
	while (i < program->philo_num)
	{
		ft_usleep(5);
		if (pthread_create(&philos[i].thread, NULL,
				&routine, &philos[i]) != 0)
			ft_destroy(program, forks);
		i++;
	}
	ft_monitor(philos, program);
	i = 0;
	while (i < program->philo_num)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			ft_destroy(program, forks);
		i++;
	}
}

void	initialize_philos(char **argv, t_prog *program, t_philo *philos,
	pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->philo_num)
	{
		philos[i].time_to_die = ft_atol(argv[2]);
		philos[i].time_to_eat = ft_atol(argv[3]);
		philos[i].time_to_sleep = ft_atol(argv[4]);
		philos[i].last_meal = ft_get_time();
		philos[i].id = i + 1;
		philos[i].l_fork = &forks[i];
		if (philos[i].id == 1)
			philos[i].r_fork = &forks[program->philo_num - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		philos[i].first_meal = ft_get_time();
		philos[i].times_eaten = 0;
		if (argv[5])
			philos[i].n_times_to_eat = ft_atol(argv[5]);
		else
			philos[i].n_times_to_eat = -1;
		philos[i].table = program;
		i++;
	}
}

void	initialize_forks(pthread_mutex_t	*forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	initialize_program(t_prog *program, t_philo *philos, char **argv)
{
	pthread_mutex_t	forks[200];

	program->philo_num = ft_atol (argv[1]);
	program->end_flag = 0;
	pthread_mutex_init(&program->monitor_lock, NULL);
	pthread_mutex_init(&program->print_lock, NULL);
	pthread_mutex_init(&program->eat_lock, NULL);
	initialize_forks(forks, program->philo_num);
	initialize_philos(argv, program, philos, forks);
	program->philos = philos;
	if (program->philo_num == 1)
	{
		print("has taken a fork", philos, philos->id, BLUE);
		ft_usleep(ft_atol(argv[2]));
		print("died", philos, philos->id, RED);
		return ;
	}
	initialize_threads(program, forks, philos);
	ft_destroy(program, forks);
}
