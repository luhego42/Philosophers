/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:36:23 by luhego            #+#    #+#             */
/*   Updated: 2024/01/03 18:54:12 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fill_arg(t_args *args, char	**argv)
{
	args->death_time = atoi(argv[2]);
	args->sleep_time = atoi(argv[4]);
	args->eat_time = atoi(argv[3]);
	if (argv[5])
		args->nb_meal = atoi(argv[5]);
	else
		args->nb_meal = -1;
	args->nb_forks = atoi(argv[1]);
	if (args->nb_forks <= 0)
	{
		printf("pas d'fourchette pas d'pastas\n");
		exit(0);
	}
}

static void	init_struct_var(t_philo **philo, t_args *args)
{
	int	i;
	t_philo	*new;

	i = 1;
	new = 0;
	while (i <= args->nb_forks)
	{
		new = malloc(sizeof(t_philo));
		new->next = 0;
		new->philo_id = i;
		new->args = args;
		lstadd_back(philo, new);
		i++;
	}
}
/*
void	print_struct_var(t_philo *philo)
{
	printf("nb_forks = %i\n", args->nb_forks);
	printf("death_time = %i\n", args->death_time);
	printf("eat_time = %i\n", philo->args->eat_time);
	printf("sleep_time = %i\n", philo->args->sleep_time);
	if (philo->args->nb_meal != 0)
		printf("meal taken\n");
	printf("nb_meal = %i\n", philo->args->nb_meal);
	while (philo)
	{
		printf("philo_id = %i\n", philo->philo_id);
		philo = philo->next;
	}
}
*/
void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	printf("philo id = %d\n", philo->philo_id);
//	print_struct_var(philo);
	return (ptr);
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philo;
	t_philo	*tmp;

	philo = 0;
	tmp = 0;
	if (argc != 5 && argc != 6)
		return (0);
	fill_arg(&args, argv);
	init_struct_var(&philo, &args);
	tmp = philo;
	while (philo)
	{
		if(pthread_create(&philo->thread, 0, routine, philo))
			perror("Error creating thread\n");
		philo = philo->next;
	}
	philo = tmp;
	while (philo)
	{
		if (pthread_join(philo->thread, 0) != 0)
			perror("Error pthread_create\n");
		philo = philo->next;
	}
	lst_clear(&tmp);
/*	if (pthread_create(philo.thread, 0, routine(t_args), &args))
		perror("Error creating thread>\n");
	pthread_join(philo.thread, 0);*/
	return (0);
}
