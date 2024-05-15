/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:27:16 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/14 20:27:17 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_forks(t_room *room)
{
	int	i;

	i = 0;
	while (i < room->philos_nbr)
	{
		pthread_mutex_destroy(&room->philo[i].mutex_philo);
		pthread_mutex_destroy(&room->forks[i]);
		i++;
	}
	return (1);
}

void	free_all(t_room *room)
{
	pthread_mutex_destroy(&room->print);
	pthread_mutex_destroy(&room->mutex_room);
	destroy_forks(room);
	free(room->forks);
	free(room->philo);
}
