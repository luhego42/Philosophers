/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:33:37 by luhego            #+#    #+#             */
/*   Updated: 2024/01/29 17:32:41 by luhego           ###   ########.fr       */
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
	pthread_mutex_t	is_dead;
	pthread_mutex_t	is_eating;
}	t_args;

typedef struct s_philo
{
	t_args			*args;
	pthread_t		thread;
	int				philo_id;
	int				meal_taken;
	size_t			last_meal;
	struct s_philo	*next;
	pthread_mutex_t	fork;
	pthread_mutex_t	*rfork;
}	t_philo;

int		ft_atoi(const char *nptr);
int		ft_print(t_philo *philo, char *str);
void	lstadd_back(t_philo **lst, t_philo *new);
void	lst_clear(t_philo **lst);
void	*routine(void *ptr);
void	print_struct_var(t_philo *philo);
void	ft_usleep(t_philo *philo, size_t sleep_time);
size_t	ft_init_actual_time(t_args *args);

#endif
