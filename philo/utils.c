/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:46:57 by jormoral          #+#    #+#             */
/*   Updated: 2024/11/19 20:41:30 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_destroy(t_prog *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->philo_num)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&program->monitor_lock);
}

int	ft_usleep(size_t milisec)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < milisec)
		usleep(10);
	return (0);
}

size_t	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_error(char *str)
{
	write(STDERR_FILENO, "Error:\n", 7);
	write(STDERR_FILENO, str, ft_strlen(str));
	return (1);
}

int	ft_atol(const char *str)
{
	int			i;
	int			sign;
	int			res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * sign);
}
