/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:20:13 by jormoral          #+#    #+#             */
/*   Updated: 2024/11/19 21:01:45 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define YELLOW "\033[0;93m"
# define BLUE "\033[0;96m"
# define GREEN "\033[0;32m"
# define ORANGE "\033[0;33m"
# define RED "\033[0;31m"
# define WHITE "\033[37;1m"

typedef struct s_list	t_prog;
typedef struct s_philo	t_philo;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				last_meal;
	size_t				first_meal;
	int					times_eaten;
	int					n_times_to_eat;
	t_prog				*table;

}	t_philo;

typedef struct s_list
{
	int					philo_num;
	int					end_flag;
	pthread_mutex_t		monitor_lock;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		eat_lock;
	t_philo				*philos;
}	t_prog;
//Main
int		check_arg(char **argv);
//Init
void	initialize_program(t_prog *program, t_philo *philos, char **argv);
void	initialize_forks(pthread_mutex_t	*forks, int philo_num);
void	initialize_philos(char **argv, t_prog *program, t_philo *philos,
			pthread_mutex_t *forks);
void	initialize_threads(t_prog *program, pthread_mutex_t *forks,
			t_philo *philos);
//Monitor
void	ft_monitor(t_philo *philos, t_prog *program);
int		ft_meal_counter(t_philo *philos, t_prog *program);
int		ft_die(t_philo *philos);
//Routine
void	*routine(void *p);
void	ft_think(t_philo *philos);
void	ft_sleep(t_philo *philos);
void	ft_eat(t_philo *philos);
void	grab_forks(t_philo *philos);
int		ft_loop(t_philo *philos);
//Print
void	print(char *str, t_philo *philos, int id, char *color);
//Utils
void	ft_destroy(t_prog *program, pthread_mutex_t *forks);
size_t	ft_get_time(void);
int		ft_usleep(size_t milisec);
int		ft_error(char *str);
int		ft_atol(const char *str);
int		ft_strlen(char *s);

#endif