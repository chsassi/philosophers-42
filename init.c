/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:28:03 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/14 20:27:17 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_room(t_room *pRoom, int ac, char **av)
{
	if (ac == 6)
		pRoom->must_eat = ft_atoi(av[5]);
	pRoom->philos_nbr = ft_atoi(av[1]);
	pRoom->time_to_die = ft_atoi(av[2]);
	pRoom->time_to_eat = ft_atoi(av[3]);
	pRoom->time_to_sleep = ft_atoi(av[4]);
	pRoom->philo = (t_philo *)malloc(sizeof(t_philo) * pRoom->philos_nbr);
	if (!pRoom->philo)
		return (0);
	pRoom->forks = malloc(sizeof(pthread_mutex_t) * pRoom->philos_nbr);
	if (!pRoom->forks)
	{
		free(pRoom->philo);
		return (0);
	}
	pthread_mutex_init(&pRoom->print, NULL);
	return (1);
}

int	assign_forks(t_room *pRoom)
{
	int	i;
	int	last;

	i = -1;
	last = pRoom->philos_nbr;
	while (++i < last)
	{
		pRoom->philo[i] = (t_philo){0};
		pthread_mutex_init(&pRoom->philo[i].mutex_philo, NULL);
		pthread_mutex_init(&pRoom->forks[i], NULL);
		pRoom->philo[i].r_fork = i;
		pRoom->philo[i].l_fork = (i - 1 + last) % last;
		if (pRoom->philos_nbr == 1)
			pRoom->philo[i].l_fork = -1;
		if (i == last - 1)
		{
			pRoom->philo[i].l_fork = i;
			pRoom->philo[i].r_fork = 0;
		}
	}
	return (1);
}

int	init_philos(t_room *pRoom)
{
	int		i;

	i = 0;
	pRoom->start_time = get_milliseconds();
	assign_forks(pRoom);
	while (i < pRoom->philos_nbr)
	{
		pRoom->philo[i].philo_index = i + 1;
		pRoom->philo[i].room_ptr = pRoom;
		pthread_create(&pRoom->philo[i].id, NULL, \
			philo_routine, &pRoom->philo[i]);
		i++;
	}
	return (1);
}

int	init(t_room *room, int ac, char **av)
{
	t_philo	*philo;

	philo = NULL;
	if (!init_room(room, ac, av))
	{
		pthread_mutex_destroy(&room->print);
		pthread_mutex_destroy(&room->mutex_room);
		return (0);
	}
	if (!init_philos(room))
	{
		destroy_forks(room);
		free(room->forks);
		free(room->philo);
		return (0);
	}
	return (1);
}
