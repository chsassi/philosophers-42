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
	int	tmp;
	int	i;

	i = 0;
	pRoom->philos_nbr = ft_atoi(av[1]);
	pRoom->philo = (t_philo *)malloc(sizeof(t_philo) * pRoom->philos_nbr);
	if (!pRoom->philo)
		return (0);
	tmp = pRoom->philos_nbr;
	while (tmp > 0)
	{
		pRoom->philo[i].time_to_die = ft_atoi(av[2]);
		pRoom->philo[i].time_to_eat = ft_atoi(av[3]);
		pRoom->philo[i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			pRoom->philo[i].must_eat = ft_atoi(av[5]);
		pRoom->philo[i].alive = true;
		i++;
		tmp--;
	}
	return (pRoom);
}

int	create_philos(t_room *pRoom, int ac, char **av)
{
	int		len;

	len = pRoom->philos_nbr;
	pRoom = init_room(pRoom, ac, av);
	while (len >= 0)
	{
		pthread_create(&pRoom, NULL, &philo_routine, NULL);
		len--;
	}
	return (0);
}
