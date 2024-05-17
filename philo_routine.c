/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:27:16 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/14 20:27:17 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	make_action(t_philo *philo)
{
	pthread_mutex_lock(&(philo->room_ptr->forks[philo->r_fork]));
	p_take_fork(philo);
	if (philo->l_fork == -1)
	{
		pthread_mutex_unlock(&(philo->room_ptr->forks[philo->r_fork]));
		return (1);
	}
	pthread_mutex_lock(&(philo->room_ptr->forks[philo->l_fork]));
	p_take_fork(philo);
	p_eat(philo);
	pthread_mutex_unlock(&(philo->room_ptr->forks[philo->r_fork]));
	pthread_mutex_unlock(&(philo->room_ptr->forks[philo->l_fork]));
	p_sleep(philo);
	p_think(philo);
	pthread_mutex_lock(&philo->room_ptr->mutex_room);
	if (philo->room_ptr->death == 1)
		return (pthread_mutex_unlock(&philo->room_ptr->mutex_room), 1);
	else
		pthread_mutex_unlock(&philo->room_ptr->mutex_room);
	pthread_mutex_lock(&philo->mutex_philo);
	if (philo->room_ptr->must_eat
		&& philo->room_ptr->must_eat <= philo->eat_count)
		return (pthread_mutex_unlock(&philo->mutex_philo), 1);
	pthread_mutex_unlock(&philo->mutex_philo);
	return (0);
}

void	*philo_routine(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	if (!(philo->philo_index % 2))
		custom_sleep(5);
	while (42)
	{
		if (make_action(philo))
			break ;
	}
	return (NULL);
}
