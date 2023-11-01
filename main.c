/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:35:46 by luhego            #+#    #+#             */
/*   Updated: 2023/11/01 16:59:58 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(int eat, int sleep, int think)
{
	while (!eat)
		think
	eat
	sleep
}
int	main(int argc, char **argv)
{
	int	philo;

	if (argv[1] == '1')
		pthread_create(thread, 0, routine(eat/sleep/think), argv);
	(void)argv;
	if (argc != 6)
	{
		
		printf("Error, wrong arguments\n");
		return (0);
	}
	printf("arguments ok\n");
	
	return (0);
}
