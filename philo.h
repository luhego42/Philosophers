/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:33:37 by luhego            #+#    #+#             */
/*   Updated: 2023/11/08 19:45:49 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_arg
{
	int	death_time;
	int	sleep_time;
	int	eat_time;
	int	nb_meal;
	int	forks;
	int	philo;

}	t_arg;

typedef	struct s_philo
{
	pthread_t	thread;
	int			philo_id;

}	t_philio;

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

#endif
