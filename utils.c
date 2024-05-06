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

	i = 0;
	if (ac < 5 || ac > 6)
		return (print_error(INVALID_ARGS));
	else if (ac == 5 || ac == 6)
	{
		while (av[i])
		{
			if (ft_atoi(av[i]) <= 0)
				return (print_error(INVALID_PARSING));
			i++;
		}
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
	return (0);
}
