/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:11:07 by luhego            #+#    #+#             */
/*   Updated: 2024/01/15 18:26:24 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_philo *philo, size_t sleep_time)
{
	ft_init_actual_time(philo->args);

	while (philo->args->actual_time < sleep_time && philo->args->kill != 1)
	{
		pthread_mutex_lock(&philo->args->is_dead);
		if (philo->args->kill != 1)
		{
			pthread_mutex_unlock(&philo->args->is_dead);
			break ;
		}
		pthread_mutex_unlock(&philo->args->is_dead);
		usleep(50);
		ft_init_actual_time(philo->args);
	}
}

void	ft_init_actual_time(t_args *args)
{
	gettimeofday(&args->tv, 0);
	args->actual_time = (args->tv.tv_sec * 1000) + (args->tv.tv_usec / 1000);
	args->actual_time = (args->actual_time - args->start);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			negative;
	long int	result;

	i = 0;
	negative = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negative = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && result < 2147483650)
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	if (result > 2147483647 && negative == 1)
		return (-1);
	if (result > 2147483648 && negative == -1)
		return (0);
	return (result * negative);
}
