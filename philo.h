/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:33:37 by luhego            #+#    #+#             */
/*   Updated: 2024/01/03 18:54:20 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_args
{
	int	death_time;
	int	sleep_time;
	int	eat_time;
	int	nb_meal;
	int	nb_forks;
}	t_args;

typedef	struct s_philo
{
	pthread_t	thread;
	int			philo_id;
	t_args		*args;
	struct s_philo		*next;

}	t_philo;

int		ft_atoi(const char *nptr);
void	lstadd_back(t_philo **lst, t_philo *new);
void	lst_clear(t_philo **lst);
//void	print_struct_var(t_philo *philo);
#endif
