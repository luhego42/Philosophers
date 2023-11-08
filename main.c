/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:35:46 by luhego            #+#    #+#             */
/*   Updated: 2023/11/08 19:45:44 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_arg	*routine;
	
	printf("ça marche\n");
	routine = (t_arg *)arg;
	printf("nb meal = %i\n", routine->nb_meal);
	while (routine->nb_meal > 0)
	{
		printf("thinking\n");
		printf("taking meal\n");
		printf("sleeping\n");
		routine->nb_meal--;
	}
	return (arg);
}

void	init_var(t_arg	*arg, char **argv)
{
	arg->death_time = atoi(argv[2]);
	arg->sleep_time = atoi(argv[3]);
	arg->philo = atoi(argv[1]);
}

void	init_philo(t_philo philo, t_arg *arg)
{
	int	i;

	i = arg->philo;
	while(i != philo)
	{
		
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_arg		arg;
	int			i;
	t_philo		*philo;

	init_var(&arg, argv);
	i = 0;
	// faire boucle d'initialisation
	// malloc
	while (i != arg.philo)
	{	
		if (pthread_create(&philo.thread, 0, routine, &arg))
			perror("Error creating thread.\n");
		philo = philo.next;
		i++;
	}
	pthread_join(thread, 0);
	if (argc != 6)
	{
		return (0);
	}
	return (0);
}
