/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:49:57 by luhego            #+#    #+#             */
/*   Updated: 2024/01/03 19:06:42 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_cycle()
{
	while (no_one_is_dead == 0)
	{
		time passed = ft_time_passed();
		printf("time : %i", time_passed);
		printf("philo : %i", philo->philo_id);
		philo_eating();
		philo_sleeeping();
		philo_thinking();
	}
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	printf("philo id = %d\n", philo->philo_id);
//	print_struct_var(philo);
	return (ptr);
}

void	philo_eating()
{	
}

void	philo_sleeping()
{
}

void	philo_thinking()
{
}
