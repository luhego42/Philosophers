/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:11:07 by luhego            #+#    #+#             */
/*   Updated: 2024/02/13 00:26:16 by luhego           ###   ########.fr       */
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
