/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:31:17 by jormoral          #+#    #+#             */
/*   Updated: 2024/11/19 20:40:58 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(char *str, t_philo *philos, int id, char *color)
{
	size_t	time;

	time = ft_get_time() - philos->first_meal;
	pthread_mutex_lock(&philos->table->print_lock);
	if (!philos->table->end_flag)
		printf("%s[%zu] %d %s\n", color, time, id, str);
	pthread_mutex_unlock(&philos->table->print_lock);
}

int	ft_loop(t_philo *philos)
{
	pthread_mutex_lock(&philos->table->print_lock);
	if (philos->table->end_flag)
	{
		pthread_mutex_unlock(&philos->table->print_lock);
		return (1);
	}
	pthread_mutex_unlock(&philos->table->print_lock);
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (i);
	while (s[i])
		i++;
	return (i);
}
