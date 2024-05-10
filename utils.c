/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:45:09 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/06 17:28:07 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	n = 0;
	sign = 1;
	while (s[i] <= 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n * sign);
}

int	parse_args(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (print_error(INVALID_ARGS), 0);
	while (av[i])
	{
		if (i == 5)
		{
			if (ft_atoi(av[i]) < 0)
				return (print_error(INVALID_PARSING), 0);
		}
		if (ft_atoi(av[1]) > 200 || ft_atoi(av[2]) < 60
			|| ft_atoi(av[3])  < 60 || ft_atoi(av[4]) < 60
			|| ft_atoi(av[i]) <= 0)
				return (print_error(INVALID_PARSING), 0);
		i++;
	}
	return (1);
}

int	get_ms(int n)
{
	struct timeval	tv;

	n = gettimeofday(&tv, 0);
	n = (tv.tv_sec * 1000);
	return (n);
}

int	print_action(t_action action_type, t_room *pRoom)
{
	if (action_type == EATING)
		printf("Philo %i is eating.\n", pRoom->philo->philo_index);
	else if (action_type == SLEEPING)
		printf("Philo %i is sleeping.\n", pRoom->philo->philo_index);
	else if (action_type == THINKING)
		printf("Philo %i is thinking.\n", pRoom->philo->philo_index);
	else if (action_type == DEAD)
		printf("Philo %i died.\n", pRoom->philo->philo_index);
	else if (action_type == TOOK_FORK)
		printf("Philo %i took the fork.\n", pRoom->philo->philo_index);
	return (0);
}

int	print_error(t_error error_type)
{
	if (error_type == INVALID_PARSING)
		printf("Error in parsing.\n");
	else if (error_type == INVALID_ARGS)
		printf("Run with ./philo [philos' number], [time to die], [time to eat] [time to sleep], [number of times]\n");
	else if (error_type == ROOM_INIT)
		printf("Error in struct's initialization.\n");
	else if (error_type == PHILO_ALLOC)
		printf("Error in philo allocation.\n");
	else if (error_type == THREAD_ERROR)
		printf("Error in thread creation.\n");
	return (0);
}
