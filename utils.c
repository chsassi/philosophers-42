/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:45:09 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/14 20:27:17 by chsassi          ###   ########.fr       */
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
			|| ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60
			|| ft_atoi(av[i]) <= 0)
			return (print_error(INVALID_PARSING), 0);
		i++;
	}
	return (1);
}

long	get_milliseconds(void)
{
	long			n;
	struct timeval	tv;

	if (!gettimeofday(&tv, 0))
	{
		n = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		return (n);
	}
	return (0);
}

long	get_time(t_philo *philo)
{
	long	time;

	time = get_milliseconds() - philo->room_ptr->start_time;
	return (time);
}

void	custom_sleep(int time_to_action)
{
	long	time;

	time = get_milliseconds();
	while (get_milliseconds() - time < time_to_action)
		usleep(time_to_action / 10);
}
