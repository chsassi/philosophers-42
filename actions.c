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
	pthread_mutex_lock(&philo->room_ptr->print);
	print_action(EATING, philo);
	pthread_mutex_unlock(&philo->room_ptr->print);
	pthread_mutex_lock(&philo->mutex_philo);
	philo->is_eating = 1;
	philo->last_meal = get_milliseconds() - philo->room_ptr->start_time;
	philo->eat_count++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mutex_philo);
	custom_sleep(philo->room_ptr->time_to_eat);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->room_ptr->print);
	print_action(SLEEPING, philo);
	pthread_mutex_unlock(&philo->room_ptr->print);
	custom_sleep(philo->room_ptr->time_to_sleep);
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
