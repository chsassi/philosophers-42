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

t_room	*init_room(t_room *pRoom, int ac, char **av)
{
	pRoom->philos_nbr = ft_atoi(av[1]);
	pRoom->philo = (t_philo *)malloc(sizeof(t_philo) * pRoom->philos_nbr);
	if (!pRoom->philo)
		return (0);
	pRoom->time_to_die = ft_atoi(av[2]);
	pRoom->time_to_eat = ft_atoi(av[3]);
	pRoom->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		pRoom->must_eat = ft_atoi(av[5]);
	return (pRoom);
}

// int	init_philos(t_philo *pPhilo, int ac, char **av)
// {
// 	int		len;
// 	t_room	*room;

// 	room = NULL;
// 	room = init_room(room, ac, av);
// 	if (!room)
// 		return (ROOM_INIT);
// 	len = room->philos_nbr;
// 	while (len >= 0)
// 	{
// 		pthread_create(&pPhilo, NULL, &philo_routine, NULL);
// 		len--;
// 	}
// 	return (1);
// }
