/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:36:23 by luhego            #+#    #+#             */
/*   Updated: 2024/02/18 21:10:09 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	fill_arg(t_args *args, char	**argv)
{
	args->stop = 0;
	args->kill = 0;
	args->philo_eat = 0;
	args->nb_forks = ft_atoi(argv[1]);
	args->death_time = ft_atoi(argv[2]);
	args->eat_time = ft_atoi(argv[3]);
	args->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		args->nb_meal = ft_atoi(argv[5]);
	else
		args->nb_meal = -1;
	if (args->nb_forks <= 0)
	{
		printf("Error, must have at least 1 philo\n");
		return (-1);
	}
	if (args->sleep_time < 1 || args->eat_time < 1 || args->death_time < 1 \
		|| (argv[5] && args->nb_meal < 1))
	{
		printf("Invalid parameters.\n");
		return (-1);
	}
	return (0);
}

static void	init_mutex(t_args *args)
{
	pthread_mutex_init(&args->is_stop, 0);
	pthread_mutex_init(&args->is_dead, 0);
	pthread_mutex_init(&args->is_writing, 0);
	pthread_mutex_init(&args->is_eating, 0);
}

static void	init_struct_var(t_philo **philo, t_args *args)
{
	t_philo	*new;
	int		i;

	i = 1;
	new = 0;
	while (i <= args->nb_forks)
	{
		new = malloc(sizeof(t_philo));
		new->next = 0;
		new->philo_id = i;
		new->meal_taken = 0;
		new->args = args;
		pthread_mutex_init(&new->left_fork, 0);
		lstadd_back(philo, new);
		i++;
	}
}

static void	launch_thread(t_philo *philo)
{
	t_philo			*tmp;
	pthread_mutex_t	*tmp_fork;

	tmp = philo;
	tmp_fork = &philo->left_fork;
	while (philo)
	{
		if (philo->next)
			philo->right_fork = &philo->next->left_fork;
		else
			philo->right_fork = tmp_fork;
		pthread_create(&philo->thread, 0, routine, philo);
		philo = philo->next;
	}
	philo = tmp;
	while (philo)
	{
		pthread_join(philo->thread, 0);
		philo = philo->next;
	}
	lst_clear(&tmp);
}

int	main(int argc, char **argv)
{
	t_args			args;
	t_philo			*philo;
	struct timeval	tv;

	philo = 0;
	if (argc != 5 && argc != 6)
	{
		printf("Invalid paramaters.\n");
		return (0);
	}
	if (fill_arg(&args, argv) == -1)
		return (0);
	init_struct_var(&philo, &args);
	init_mutex(&args);
	gettimeofday(&tv, 0);
	args.start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	launch_thread(philo);
	return (0);
}
