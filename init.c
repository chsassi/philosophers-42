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

int	assign_forks(t_room *pRoom, int i)
{
	int	check;

	if (i == pRoom->philos_nbr - 1)
	{
		check = pthread_mutex_init(&pRoom->forks[i], NULL);
		if (check == -1)
			return (0);
		pRoom->philo[i].r_fork = &pRoom->forks[i];
		pRoom->philo[i].l_fork = &pRoom->forks[0];
		return (1);
	}
	check = pthread_mutex_init(&pRoom->forks[i], NULL);
	if (check == -1)
		return (0);
	check = pthread_mutex_init(&pRoom->forks[i + 1], NULL);
	if (check == -1)
		return (0);
	pRoom->philo[i].r_fork = &pRoom->forks[i];
	pRoom->philo[i].l_fork = &pRoom->forks[i + 1];
	return (1);
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
		pRoom->philo[i].philo_index = i + 1;
		pRoom->philo[i].last_meal = 0;
		pRoom->philo[i].room_ptr = pRoom;
		assign_forks(pRoom, i);
		check = pthread_create(&pRoom->philo->id, NULL, &philo_routine, NULL);
		if (check != 0)
		{
			print_error(THREAD_ERROR);
			return ;
		}
		i++;
		len--;
	}
	pthread_join(pRoom->philo->id, NULL);
}
