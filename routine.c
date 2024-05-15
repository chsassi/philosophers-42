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

int	do_action(t_philo *philo)
{
	pthread_mutex_lock(&(philo->room_ptr->forks[philo->r_fork]));
	took_fork(philo);
	if (!&philo->room_ptr->forks[philo->l_fork])
	{
		usleep(philo->room_ptr->time_to_die);
		death(philo);
		pthread_mutex_unlock(&(philo->room_ptr->forks[philo->r_fork]));
		return (1);
	}
	pthread_mutex_lock(&(philo->room_ptr->forks[philo->l_fork]));
	took_fork(philo);
	eating(philo);
	pthread_mutex_unlock(&(philo->room_ptr->forks[philo->r_fork]));
	pthread_mutex_unlock(&(philo->room_ptr->forks[philo->l_fork]));
	sleeping(philo);
	thinking(philo);
	pthread_mutex_lock(&philo->mutex_philo);
	if (philo->room_ptr->death == 1
		|| &philo->room_ptr->must_eat == &philo->eat_count)
	{
		pthread_mutex_unlock(&philo->mutex_philo);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex_philo);
	return (1);
}

void	*philo_routine(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	pthread_mutex_init(&philo->mutex_philo, NULL);
	while (42)
	{
		if (do_action(philo))
			break ;
	}
	return (pthread_mutex_destroy(&philo->mutex_philo), NULL);
}
