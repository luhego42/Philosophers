/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:49:57 by luhego            #+#    #+#             */
/*   Updated: 2024/02/12 22:28:13 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo, int nb)
{
	pthread_mutex_lock(&philo->args->is_dead);
	if (nb)
		philo->args->kill = 1;
	if (philo->args->kill != 1)
	{
		pthread_mutex_unlock(&philo->args->is_dead);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&philo->args->is_dead);
		return (1);
	}
}

void	ft_print_status(t_philo *philo, char *status)
{
	size_t	time;

	time = ft_init_actual_time(philo->args);
	pthread_mutex_lock(&philo->args->is_writing);
	if (!check_death(philo, 0))
		printf("%ldms %i %s\n", time, philo->philo_id, status);
	pthread_mutex_unlock(&philo->args->is_writing);
}

void	single_fork_scenario(t_philo *philo)
{
	ft_print_status(philo, "Has taken a fork");
	usleep(philo->args->death_time * 1000);
	ft_print_status(philo, "Is dead");
}

int	has_finished_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->is_eating);
	if (philo->meal_taken == philo->args->nb_meal)
	{
		philo->args->philo_eat += 1;
		pthread_mutex_lock(&philo->args->is_stop);
		if (philo->args->philo_eat == philo->args->nb_forks)
		{
			philo->args->stop = 1;
			pthread_mutex_unlock(&philo->args->is_stop);
			pthread_mutex_unlock(&philo->args->is_eating);
			return (1);
		}
		pthread_mutex_unlock(&philo->args->is_stop);
	}
	pthread_mutex_unlock(&philo->args->is_eating);
	return (0);
}
