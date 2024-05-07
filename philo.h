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

typedef enum	e_error
{
	INVALID_PARSING,
	INVALID_ARGS,
	PHILO_ALLOC,
	THREAD_ERROR,
	ROOM_INIT
}	t_error;

typedef struct	s_room t_room;

typedef struct	s_philo
{
	pthread_t	id;
	int			philo_index;
	int			last_meal;
	t_room		*room_ptr;
}	t_philo;

typedef struct	s_room
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				philos_nbr;
	int				eat_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
}	t_room;

/* Init */

void	init_room(t_room *pRoom, int ac, char **av);
void	init_philos(t_room *pRoom);

/* Utils */

int		ft_atoi(char *s);
int		get_ms(int n);
int		parse_args(int ac, char **av);
void	*philo_routine(void *var);
int		print_error(t_error error_type);

#endif