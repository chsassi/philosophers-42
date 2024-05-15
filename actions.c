/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:27:16 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/14 20:27:17 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	took_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->room_ptr->print);
	print_action(TOOK_FORK, philo);
	pthread_mutex_unlock(&philo->room_ptr->print);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_philo);
	philo->last_meal = get_milliseconds();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutex_philo);
	usleep(philo->room_ptr->time_to_eat);
	pthread_mutex_lock(&philo->room_ptr->print);
	print_action(EATING, philo);
	pthread_mutex_unlock(&philo->room_ptr->print);
}

void	sleeping(t_philo *philo)
{
	usleep(philo->room_ptr->time_to_sleep);
	pthread_mutex_lock(&philo->room_ptr->print);
	print_action(SLEEPING, philo);
	pthread_mutex_unlock(&philo->room_ptr->print);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->room_ptr->print);
	print_action(THINKING, philo);
	pthread_mutex_unlock(&philo->room_ptr->print);
}

void	death(t_philo *philo)
{
	pthread_mutex_lock(&philo->room_ptr->print);
	print_action(DEAD, philo);
	pthread_mutex_unlock(&philo->room_ptr->print);
}
