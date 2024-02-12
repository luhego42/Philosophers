/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:11:07 by luhego            #+#    #+#             */
/*   Updated: 2024/02/11 21:57:20 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_philo *philo, size_t sleep_time)
{
	size_t	time;
	size_t	time_passed;

	time = ft_init_actual_time(philo->args);
	time_passed = time;
	while (time_passed - time < sleep_time)
	{
		usleep(50);
		time_passed = ft_init_actual_time(philo->args);
	}
}

size_t	ft_init_actual_time(t_args *args)
{
	size_t			time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	time = time - args->start;
	return (time);
}
