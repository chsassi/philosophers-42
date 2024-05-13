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

typedef enum	e_action
{
	TOOK_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_action;

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
	pthread_t		id;
	int				philo_index;
	int				last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_room			*room_ptr;
}	t_philo;

typedef struct	s_room
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	int				philos_nbr;
	int				eat_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
}	t_room;

/* Init */

void			init_room(t_room *pRoom, int ac, char **av);
int				assign_forks(t_room *pRoom, int i);
void			init_philos(t_room *pRoom);

/* Routine */

int				start_eating(t_room *pRoom);
void			*philo_routine(void *var);

/* Utils */

int				ft_atoi(char *s);
unsigned long	get_ms(void);
int				parse_args(int ac, char **av);
int				print_action(t_action action_type, t_room *pRoom);
int				print_error(t_error error_type);

#endif