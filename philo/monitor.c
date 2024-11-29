/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:43:19 by jormoral          #+#    #+#             */
/*   Updated: 2024/11/20 11:02:49 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_die(t_philo *philos)
{
	pthread_mutex_lock(&philos->table->monitor_lock);
	if (ft_get_time() - philos->last_meal >= philos->time_to_die)
	{
		print("died", philos, philos->id, RED);
		pthread_mutex_unlock(&philos->table->monitor_lock);
		return (1);
	}
	pthread_mutex_unlock(&philos->table->monitor_lock);
	return (0);
}

int	ft_meal_counter(t_philo *philos, t_prog *program)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	if (philos->n_times_to_eat == -1)
		return (0);
	while (i < program->philo_num)
	{
		ft_usleep(4);
		pthread_mutex_lock(&philos->table->monitor_lock);
		if (philos[i].times_eaten >= philos->n_times_to_eat)
			counter++;
		pthread_mutex_unlock(&philos->table->monitor_lock);
		if (counter == program->philo_num)
			return (1);
		i++;
	}
	return (0);
}

void	ft_monitor(t_philo *philos, t_prog *program)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == program->philo_num)
		{
			i = 0;
		}
		if (ft_die(&philos[i]) || ft_meal_counter(&philos[i], program))
		{
			pthread_mutex_lock(&philos->table->print_lock);
			program->end_flag = 1;
			break ;
		}
		ft_usleep(1);
		i++;
	}
	pthread_mutex_unlock(&philos->table->print_lock);
}
