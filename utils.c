/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:45:09 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/01 18:45:12 by chsassi          ###   ########.fr       */
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
	t_philo	*ptr;

	ptr = NULL;
	i = 0;
	if (ac == 5 || ac == 6)
	{
		while (av[i])
		{
			if (ft_atoi(av[i]) <= 0)
				return (0);
			i++;
		}
	}
}

int	get_ms(int n)
{
	struct timeval	tv;

	n = gettimeofday(&tv, 0);
	n = (tv.tv_sec * 1000);
	return (n);
}

// void	*philo_routine(void *var)
// {
	
// }