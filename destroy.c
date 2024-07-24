/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:27:16 by chsassi           #+#    #+#             */
/*   Updated: 2024/07/24 09:51:12 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_forks(t_room *pRoom)
{
	int	i;

	i = 0;
	while (i < pRoom->philos_nbr)
	{
		pthread_mutex_destroy(&pRoom->philo[i].mutex_philo);
		pthread_mutex_destroy(&pRoom->forks[i]);
		i++;
	}
	return (1);
}

void	free_all(t_room *pRoom)
{
	pthread_mutex_destroy(&pRoom->print);
	pthread_mutex_destroy(&pRoom->mutex_room);
	destroy_forks(pRoom);
	free(pRoom->forks);
	free(pRoom->philo);
}
