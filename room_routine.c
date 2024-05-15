/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:27:16 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/14 20:27:17 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philos(t_room *room)
{
	int	philos_nbr;
	int	must_eat;
	int	i;

	philos_nbr = room->philos_nbr;
	must_eat = 0;
	i = 0;
	while (philos_nbr)
	{
		pthread_mutex_lock(&room->philo[i].mutex_philo);
		room->time = (get_milliseconds() - room->start_time) \
		 - room->philo[i].last_meal;
		pthread_mutex_unlock(&room->philo[i].mutex_philo);
		if (room->time >= room->time_to_die)
		{
			room->death = 1;
			death(&room->philo[i]);
			return (0);
		}
		pthread_mutex_lock(&room->philo[i].mutex_philo);
		if (room->philo[i].eat_count == must_eat)
		{
			pthread_mutex_unlock(&room->philo[i].mutex_philo);
			break ;
		}
		pthread_mutex_unlock(&room->philo[i].mutex_philo);
		i++;
	}
	return (1);
}

void	room_routine(t_room *room)
{
	int	i;
	int	must_eat;

	i = 0;
	must_eat = room->must_eat;
	while (42)
	{
		if (!check_philos(room))
			break ;
	}
	while (i < room->philos_nbr)
	{
		pthread_join(room->philo[i].id, NULL);
		i++;
	}
}
