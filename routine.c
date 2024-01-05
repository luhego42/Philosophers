/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:49:57 by luhego            #+#    #+#             */
/*   Updated: 2024/01/05 19:50:28 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, char *str)
{
	ft_init_actual_time(philo->args);
	printf("%ld %i %s\n", philo->args->actual_time, philo->philo_id, str);
}

void	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->rfork);
	ft_print(philo, "Is eating\n");
	usleep(1000000);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->rfork);
	
}

void	philo_sleeping(t_philo *philo)
{
	ft_print(philo, "Is sleeping zZzZzZ\n");
	usleep(1000000);
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
		usleep(5000);
	printf("philo %d\n", philo->philo_id);
	philo_eating(philo);
	philo_sleeping(philo);
	pthread_mutex_unlock(&philo->args->is_dead);
	philo_thinking(philo);
//	print_struct_var(philo);
	return (ptr);
}
