/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:01:47 by jormoral          #+#    #+#             */
/*   Updated: 2024/11/27 10:14:30 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	grab_forks(t_philo *philos)
{
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(philos->r_fork);
		print("has taken a fork", philos, philos->id, ORANGE);
		pthread_mutex_lock(philos->l_fork);
		print("has taken a fork", philos, philos->id, ORANGE);
	}
	else
	{
		pthread_mutex_lock(philos->l_fork);
		print("has taken a fork", philos, philos->id, ORANGE);
		pthread_mutex_lock(philos->r_fork);
		print("has taken a fork", philos, philos->id, ORANGE);
	}
}

void	ft_eat(t_philo *philos)
{
	grab_forks(philos);
	pthread_mutex_lock(&philos->table->monitor_lock);
	philos->last_meal = ft_get_time();
	philos->times_eaten++;
	pthread_mutex_unlock(&philos->table->monitor_lock);
	print("is eating", philos, philos->id, GREEN);
	ft_usleep(philos->time_to_eat);
	pthread_mutex_unlock(philos->l_fork);
	pthread_mutex_unlock(philos->r_fork);
}

void	ft_sleep(t_philo *philos)
{
	print("is sleeping", philos, philos->id, BLUE);
	ft_usleep(philos->time_to_sleep);
}

void	ft_think(t_philo *philos)
{
	print("is thinking", philos, philos->id, WHITE);
	ft_usleep (1);
}

void	*routine(void *p)
{
	t_philo	*philos;

	philos = (t_philo *)p;
	if (philos->id % 2 == 0)
		ft_usleep(10);
	while (!ft_loop(philos))
	{
		ft_eat(philos);
		ft_sleep(philos);
		ft_think(philos);
	}
	return (p);
}
