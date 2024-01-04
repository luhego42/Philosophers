/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:49:57 by luhego            #+#    #+#             */
/*   Updated: 2024/01/04 19:55:56 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
void	ft_print_cycle()
{
	while (no_one_is_dead() == 0)
	{
		time passed = ft_time_passed();
		printf("time : %i", time_passed);
		printf("philo : %i", philo->philo_id);
		philo_eating();
		philo_sleeeping();
		philo_thinking();
	}
}
*/

void	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->rfork);
	printf("I'm eating miom\n");
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->rfork);
	
}

void	philo_sleeping(void) // print
{
	printf("I'm sleeping ronk\n");
}

void	philo_thinking(void) // print
{
	printf("I'm thinking not too much\n");
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->philo_id % 2 == 0)
		usleep(5000);
	printf("philo %d\n", philo->philo_id);
	philo_eating(philo);
	philo_sleeping();
	pthread_mutex_unlock(&philo->args->mutex);
	philo_thinking();
//	print_struct_var(philo);
	return (ptr);
}
