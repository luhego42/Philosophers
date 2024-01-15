/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:33:37 by luhego            #+#    #+#             */
/*   Updated: 2024/01/15 18:33:03 by luhego           ###   ########.fr       */
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
	size_t	death_time;
	size_t	sleep_time;
	int	eat_time;
	int	nb_meal;
	int	nb_forks;
	int	kill;
	size_t	start;
	size_t	actual_time;
	struct timeval	tv;
	pthread_mutex_t	is_dead;
}	t_args;

typedef	struct s_philo
{
	pthread_t	thread;
	int			philo_id;
	int			meal_taken;
	t_args		*args;
	struct s_philo		*next;
	pthread_mutex_t	fork;
	pthread_mutex_t	*rfork;
}	t_philo;

int		ft_atoi(const char *nptr);
void	lstadd_back(t_philo **lst, t_philo *new);
void	lst_clear(t_philo **lst);
void	*routine(void *ptr);
void	ft_init_actual_time(t_args *args);
void	print_struct_var(t_philo *philo);
void	ft_usleep(t_philo *philo, size_t sleep_time);
int	ft_print(t_philo *philo, char *str);
#endif
