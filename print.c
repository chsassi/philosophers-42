/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:34:07 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/14 20:34:09 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_action(t_action action_type, t_philo *philo)
{
	long	time;

	time = get_time(philo);
	if (!check_print(philo))
		return (1);
	if (action_type == EATING)
		printf("\e[0;31m%li, Philo %i is eating.\e[0m\n", \
		time, philo->philo_index);
	else if (action_type == SLEEPING)
		printf("\e[0;32m%li, Philo %i is sleeping.\e[0m\n", \
		time, philo->philo_index);
	else if (action_type == THINKING)
		printf("\e[0;34m%li, Philo %i is thinking.\e[0m\n", \
		time, philo->philo_index);
	else if (action_type == DEAD)
		printf("\e[0;36m%li, Philo %i died.\e[0m\n", \
		time, philo->philo_index);
	else if (action_type == TOOK_FORK)
		printf("%li, Philo %i took a fork.\n", time, philo->philo_index);
	return (0);
}

int	print_error(t_error error_type)
{
	if (error_type == INVALID_PARSING)
		printf("Error in parsing.\n");
	else if (error_type == INVALID_ARGS)
		printf("Run with ./philo [philos' number], \
		[time to die], [time to eat] [time to sleep], [number of times]\n");
	else if (error_type == ROOM_INIT)
		printf("Error in struct's initialization.\n");
	else if (error_type == PHILO_ALLOC)
		printf("Error in philo allocation.\n");
	else if (error_type == THREAD_ERROR)
		printf("Error in thread creation.\n");
	return (0);
}

int	check_print(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_philo);
	if (philo->room_ptr->death == 1
		|| philo->room_ptr->must_eat == philo->eat_count)
	{
		pthread_mutex_unlock(&philo->mutex_philo);
		return (0);
	}
	pthread_mutex_unlock(&philo->mutex_philo);
	return (1);
}
