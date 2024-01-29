/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:36:23 by luhego            #+#    #+#             */
/*   Updated: 2024/01/28 18:16:29 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fill_arg(t_args *args, char	**argv)
{
	args->nb_forks = atoi(argv[1]);
	args->death_time = atoi(argv[2]);
	args->eat_time = atoi(argv[3]);
	args->sleep_time = atoi(argv[4]);
	if (argv[5])
		args->nb_meal = atoi(argv[5]);
	else
		args->nb_meal = -1;
	if (args->nb_forks <= 0)
	{
		printf("Error, must have at least 1 philo\n");
		exit(0);
	}
	pthread_mutex_init(&args->is_dead, 0);
	pthread_mutex_init(&args->is_eating, 0);
}

static void	init_struct_var(t_philo **philo, t_args *args)
{
	t_philo	*new;
	int	i;
	
	i = 1;
	new = 0;
	while (i <= args->nb_forks)
	{
		new = malloc(sizeof(t_philo));
		new->next = 0;
		new->philo_id = i;
		new->meal_taken = 0;
		new->args = args;
		pthread_mutex_init(&new->fork, 0);
		lstadd_back(philo, new);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_args			args;
	t_philo			*philo;
	t_philo			*tmp;
	pthread_mutex_t	*tmp_fork;
	struct timeval	tv;

	philo = 0;
	tmp = 0;
	if (argc != 5 && argc != 6)
		return (0);
	fill_arg(&args, argv);
	init_struct_var(&philo, &args);
	philo->args->kill = 0; // tesst
	tmp = philo;
	gettimeofday(&tv, 0);
	args.start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	tmp_fork = &philo->fork;
	while (philo)
	{
		if (philo->next)
			philo->rfork = &philo->next->fork;
		else
			philo->rfork = tmp_fork;
		if(pthread_create(&philo->thread, 0, routine, philo))
			perror("Error, pthread_create\n");
		philo = philo->next;
	}
	philo = tmp;
	while (philo)
	{
		if (pthread_join(philo->thread, 0) != 0)
			perror("Error, pthread_join\n");
		philo = philo->next;
	}
	lst_clear(&tmp);
	return (0);
}
