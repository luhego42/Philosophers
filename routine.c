/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:49:57 by luhego            #+#    #+#             */
/*   Updated: 2024/01/28 19:42:48 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h> // to_rm

int	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	if (ft_print(philo, "Has taken a fork\n") == -1)
		return (-1);
	pthread_mutex_lock(philo->rfork);
	if (ft_print(philo, "Has taken a fork\n") == -1)
		return (-1);
	philo->last_meal = ft_init_actual_time(philo->args);
	if (ft_print(philo, "Is eating\n") == -1)
		return (-1);
	ft_usleep(philo, philo->args->eat_time);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_lock(&philo->args->is_eating);
	philo->meal_taken++;
	if (philo->meal_taken == philo->args->nb_meal)
	{
		pthread_mutex_unlock(&philo->args->is_eating);
		return (-1);
	}	
	pthread_mutex_unlock(&philo->args->is_eating);
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
	size_t	time;

	time = ft_init_actual_time(philo->args);
	pthread_mutex_lock(&philo->args->is_dead);
	if (philo->args->kill == 1)
	{
		pthread_mutex_unlock(&philo->args->is_dead);
		return (-1);
	}
	if (time - philo->last_meal > philo->args->death_time)
	{
		printf("%ld %i Is dead\n", time, philo->philo_id);
		philo->args->kill = 1;
		pthread_mutex_unlock(&philo->args->is_dead);
		return (-1);
	}
	printf("%ld %i %s\n", time, philo->philo_id, str);
	pthread_mutex_unlock(&philo->args->is_dead);
	return (1);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	philo->last_meal = 0;
	if (philo->args->nb_forks == 1)
	{
		ft_print(philo, "Has taken a fork");
		usleep(philo->args->death_time * 1000);
		ft_print(philo, "is Dead");
		return (0);
	}
	if (philo->philo_id % 2 == 0)
		ft_usleep(philo, 5);
	while (1)
	{
		if (philo_eating(philo) == -1)
			break ;
		if (philo_sleeping(philo) == -1)
			break ;
		if (philo_thinking(philo) == -1)
			break ;
	}
	return (ptr);
}
