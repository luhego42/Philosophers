/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:49:57 by luhego            #+#    #+#             */
/*   Updated: 2024/01/13 17:46:09 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, char *str)
{	
	pthread_mutex_lock(&philo->args->is_dead);
	ft_init_actual_time(philo->args);
	if (philo->args->actual_time > philo->args->death_time)
	ft_print(philo, "Is dead");
	pthread_mutex_unlock(&philo->args->is_dead);
	printf("%ld %i %s\n", philo->args->actual_time, philo->philo_id, str);
}

void	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->rfork);
	ft_print(philo, "Is eating\n");
	ft_usleep(philo->args->eat_time);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->rfork);	
}

void	philo_sleeping(t_philo *philo)
{
	ft_print(philo, "Is sleeping zZzZzZ\n");
	ft_usleep(philo->args->sleep_time);
}

void	philo_thinking(t_philo *philo)
{
	ft_print(philo ,"Is Thinking\n");
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->philo_id % 2 == 0)
		usleep(50);
	while (1)
	{
		philo_eating(philo);
		philo_sleeping(philo);
		philo_thinking(philo);
	}
	return (ptr);
}
