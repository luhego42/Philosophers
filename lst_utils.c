/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:12:29 by luhego            #+#    #+#             */
/*   Updated: 2024/01/03 14:05:30 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lst_clear(t_philo **lst)
{
	t_philo	*tmp;

	tmp = *lst;
	while (tmp)
	{
		*lst = (*lst)->next;
		free(tmp);
		tmp = *lst;
	}
}

void	lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*tmp;

	if (*lst == 0)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
