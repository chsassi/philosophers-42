/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:45:22 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/01 18:45:23 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_room t_room;

typedef struct	s_philo
{
	pthread_t	*philo_id;
	int 		id;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	bool		alive;
	t_room		*room;
}	t_philo;

typedef struct	s_room
{
	t_philo	*philo;
	int		philos_nbr;
}	t_room;

/* Init */

t_room	*init_room(t_room *pRoom, int ac, char **av);
int		create_philos(t_room *pRoom, int ac, char **av);

/* Utils */

int		ft_atoi(char *s);
int		get_ms(int n);
int		parse_args(int ac, char **av);
void	*philo_routine(void *var);

#endif