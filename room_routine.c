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

int	check_task(t_room *pRoom)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	pthread_mutex_lock(&pRoom->philo[i].mutex_philo);
	if (pRoom->philo[i].eat_count == pRoom->must_eat)
	{
		pthread_mutex_unlock(&pRoom->philo[i].mutex_philo);
		if (count == pRoom->philos_nbr)
			return (EXIT_LOOP);
		count++;
	}
	pthread_mutex_unlock(&pRoom->philo[i].mutex_philo);
	return (0);
}

int	check_philos(t_room *pRoom)
{
	int	philos_nbr;
	int	i;

	philos_nbr = pRoom->philos_nbr;
	i = 0;
	while (philos_nbr)
	{
		pthread_mutex_lock(&pRoom->philo[i].mutex_philo);
		pRoom->time = (get_milliseconds() - pRoom->start_time) \
		- pRoom->philo[i].last_meal;
		pthread_mutex_unlock(&pRoom->philo[i].mutex_philo);
		if (pRoom->time >= pRoom->time_to_die)
		{
			death(&pRoom->philo[i]);
			pRoom->death = 1;
			return (0);
		}
		if (pRoom->must_eat && check_task(pRoom) == EXIT_LOOP)
			return (0);
		i++;
	}
	return (1);
}

void	room_routine(t_room *pRoom)
{
	int	i;
	int	must_eat;

	i = 0;
	must_eat = pRoom->must_eat;
	while (42)
	{
		if (!check_philos(pRoom))
			break ;
	}
	while (i < pRoom->philos_nbr)
	{
		pthread_join(pRoom->philo[i].id, NULL);
		i++;
	}
}
