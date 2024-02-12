/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:49:57 by luhego            #+#    #+#             */
/*   Updated: 2024/02/12 22:50:33 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_death(void *phi)
{
	t_philo	*philo;
	size_t	is_dead;

	philo = (t_philo *)phi;
	ft_usleep(philo, philo->args->death_time + 1);
	pthread_mutex_lock(&philo->args->is_eating);
	pthread_mutex_lock(&philo->args->is_stop);
	is_dead = ft_init_actual_time(philo->args) - philo->last_meal;
	if (!check_death(philo, 0) && (is_dead >= philo->args->death_time))
	{
		ft_print_status(philo, "Is dead");
		philo->args->kill = 1;
		pthread_mutex_unlock(&philo->args->is_stop);
		pthread_mutex_unlock(&philo->args->is_eating);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->args->is_stop);
	pthread_mutex_unlock(&philo->args->is_eating);
	return (NULL);
}
