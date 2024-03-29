/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:49:57 by luhego            #+#    #+#             */
/*   Updated: 2024/02/18 21:22:46 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	ft_print_status(philo, "Has taken a fork");
	if (has_finished_eating(philo))
		return ;
	pthread_mutex_lock(philo->right_fork);
	ft_print_status(philo, "Has taken a fork");
}

static int	eat_meal(t_philo *philo)
{
	take_forks(philo);
	if (has_finished_eating(philo))
	{
		release_forks(philo);
		return (-1);
	}
	ft_print_status(philo, "Is eating");
	pthread_mutex_lock(&philo->args->is_eating);
	philo->meal_taken++;
	philo->last_meal = ft_init_actual_time(philo->args);
	pthread_mutex_unlock(&philo->args->is_eating);
	ft_usleep(philo, philo->args->eat_time);
	release_forks(philo);
	return (0);
}

static void	*philo_routine(void *ptr)
{
	pthread_t	death_thread;
	t_philo		*philo;

	philo = (t_philo *) ptr;
	philo->last_meal = 0;
	while (!check_death(philo, 0))
	{
		pthread_create(&death_thread, NULL, monitor_death, ptr);
		if (eat_meal(philo) == -1)
		{
			pthread_join(death_thread, 0);
			break ;
		}
		ft_print_status(philo, "Is sleeping");
		ft_usleep(philo, philo->args->sleep_time);
		ft_print_status(philo, "Is thinking");
		if (has_finished_eating(philo))
		{
			pthread_join(death_thread, 0);
			break ;
		}
		pthread_join(death_thread, 0);
	}
	return (0);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *) ptr;
	if (philo->args->nb_forks == 1)
	{
		single_fork_scenario(philo);
		return (0);
	}
	if (philo->philo_id % 2 == 0)
		ft_usleep(philo, philo->args->eat_time);
	philo_routine(ptr);
	return (0);
}
