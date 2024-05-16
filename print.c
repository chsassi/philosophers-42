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

// int	print_action(t_action action_type, t_philo *philo)
// {
// 	long	time;

// 	time = get_time(philo);
// 	if (action_type != DEAD && !check_print(philo))
// 		return (1);
// 	if (action_type == EATING)
// 		printf("%li %i is eating\n", \
// 		time, philo->philo_index);
// 	else if (action_type == SLEEPING)
// 		printf("%li %i is sleeping\n", \
// 		time, philo->philo_index);
// 	else if (action_type == THINKING)
// 		printf("%li %i is thinking\n", \
// 		time, philo->philo_index);
// 	else if (action_type == DEAD)
// 		printf("%li %i died\n", \
// 		time, philo->philo_index);
// 	else if (action_type == TOOK_FORK)
// 		printf("%li %i has taken a fork\n", \
// 		time, philo->philo_index);
// 	return (0);
// }

int	print_action(t_action action_type, t_philo *philo)
{
	long	time;

	time = get_time(philo);
	if (action_type != DEAD && !check_print(philo))
		return (1);
	if (action_type == EATING)
		printf("\e[0;31m[%li] philo %i is eating.\e[0m\n", \
		time, philo->philo_index);
	else if (action_type == SLEEPING)
		printf("\e[0;32m[%li] philo %i is sleeping.\e[0m\n", \
		time, philo->philo_index);
	else if (action_type == THINKING)
		printf("\e[0;34m[%li] philo %i is thinking.\e[0m\n", \
		time, philo->philo_index);
	else if (action_type == DEAD)
		printf("\e[0;36m[%li] philo %i died.\e[0m\n", \
		time, philo->philo_index);
	else if (action_type == TOOK_FORK)
		printf("[%li] philo %i took a fork.\n", \
		time, philo->philo_index);
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
	pthread_mutex_lock(&philo->room_ptr->mutex_room);
	if (philo->room_ptr->death == 1
		|| (philo->room_ptr->must_eat
			&& philo->room_ptr->must_eat == philo->eat_count))
		return (pthread_mutex_unlock(&philo->room_ptr->mutex_room), 0);
	pthread_mutex_unlock(&philo->room_ptr->mutex_room);
	return (1);
}
