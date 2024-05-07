/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:28:03 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/06 17:28:07 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_room(t_room *pRoom, int ac, char **av)
{
	// pRoom = (t_room *){0};
	// pRoom->philo = (t_room *)malloc(sizeof(t_room) * ft_atoi(av[1]));
	pRoom->philos_nbr = ft_atoi(av[1]);
	pRoom->philo = (t_philo *)malloc(sizeof(t_philo) * pRoom->philos_nbr);
	if (!pRoom->philo)
		return ;
	pRoom->forks = malloc(sizeof(pthread_mutex_t) * pRoom->philos_nbr);
	if (!pRoom->forks)
	{
		free(pRoom->philo);
		return ;
	}
	pRoom->time_to_die = ft_atoi(av[2]);
	pRoom->time_to_eat = ft_atoi(av[3]);
	pRoom->time_to_sleep = ft_atoi(av[4]);
	if (ac == 7)
		pRoom->must_eat = ft_atoi(av[5]);
}

void	*philo_routine(void *var)
{
	(void)var;
	printf("Isso boa");
	return (0);
}

void	init_philos(t_room *pRoom)
{
	int		len;
	int		check;
	int		i;

	i = 0;
	check = 0;
	len = pRoom->philos_nbr;
	while (len >= 0)
	{
		check = pthread_create(&pRoom->philo->id, NULL, &philo_routine, NULL);
		if (check != 0)
		{
			print_error(THREAD_ERROR);
			return ;
		}
		pRoom->philo[i].philo_index = i;
		pRoom->philo[i].last_meal = 0;
		pRoom->philo[i].room_ptr = pRoom;
		i++;
		len--;
	}
}
