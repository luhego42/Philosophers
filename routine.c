/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:49:57 by luhego            #+#    #+#             */
/*   Updated: 2024/01/15 18:34:44 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h> // to_rm

int	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->rfork);
	if (ft_print(philo, "Is eating\n") == -1)
		return (-1);
	ft_usleep(philo, philo->args->eat_time);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->rfork);
	philo->meal_taken++;
	return (1);
}

int	philo_sleeping(t_philo *philo)
{
	if (ft_print(philo, "Is sleeping zZzZzZ\n") == -1)
		return (-1);
	ft_usleep(philo, philo->args->sleep_time);
	return (1);
}

int	philo_thinking(t_philo *philo)
{
	if (ft_print(philo ,"Is Thinking\n") == -1)
		return (-1);
	return (1);
}

int	ft_print(t_philo *philo, char *str)
{	
	pthread_mutex_lock(&philo->args->is_dead);
	ft_init_actual_time(philo->args);
	if (philo->args->kill == 1)
		return (-1);
	if (philo->args->actual_time > philo->args->death_time)
	{
		printf("%ld %i Is dead\n", philo->args->actual_time, philo->philo_id);
		philo->args->kill = 1;
		pthread_mutex_unlock(&philo->args->is_dead);
	}
	pthread_mutex_unlock(&philo->args->is_dead);
	printf("%ld %i %s\n", philo->args->actual_time, philo->philo_id, str);
	return (1);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->philo_id % 2 == 0)
		usleep(50);
	while (philo->meal_taken < philo->args->nb_meal)
	{
		if (philo_eating(philo) == -1)
			break ;
		if (philo_sleeping(philo) == -1)
			break ;
		if (philo_thinking(philo) == -1)
			break;
	}
	return (ptr);
}
