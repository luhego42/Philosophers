/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:33:37 by luhego            #+#    #+#             */
/*   Updated: 2024/02/13 00:26:18 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
	size_t			death_time;
	size_t			sleep_time;
	size_t			start;
	int				eat_time;
	int				nb_meal;
	int				nb_forks;
	int				kill;
	int				stop;
	int				philo_eat;
	pthread_mutex_t	is_dead;
	pthread_mutex_t	is_fork;
	pthread_mutex_t	is_writing;
	pthread_mutex_t	is_eating;
	pthread_mutex_t	is_stop;
	pthread_mutex_t	time;
}	t_args;

typedef struct s_philo
{
	pthread_t		thread;
	int				philo_id;
	int				meal_taken;
	t_args			*args;
	size_t			last_meal;
	struct s_philo	*next;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

int		ft_atoi(const char *nptr);
void	lstadd_back(t_philo **lst, t_philo *new);
void	lst_clear(t_philo **lst);
void	*routine(void *ptr);
size_t	ft_init_actual_time(t_args *args);
void	print_struct_var(t_philo *philo);
void	ft_usleep(t_philo *philo, size_t sleep_time);
int		ft_print(t_philo *philo, char *str);
void	*monitor_death(void *phi);
void	ft_print_status(t_philo *philo, char *status);
void	single_fork_scenario(t_philo *philo);
int		has_finished_eating(t_philo *philo);
int		check_death(t_philo *philo, int nb);
int		ft_atoi(const char *nptr);

#endif
