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

typedef enum e_action
{
	TOOK_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_action;

typedef enum e_error
{
	INVALID_PARSING,
	INVALID_ARGS,
	PHILO_ALLOC,
	THREAD_ERROR,
	MUTEX_ERROR,
	EXIT_LOOP,
	ROOM_INIT
}	t_error;

typedef struct s_room	t_room;

typedef struct s_philo
{
	pthread_t		id;
	int				philo_index;
	int				l_fork;
	int				r_fork;
	int				last_meal;
	int				is_eating;
	int				eat_count;
	int				status;
	pthread_mutex_t	mutex_philo;
	t_room			*room_ptr;
}	t_philo;

typedef struct s_room
{
	int				philos_nbr;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long			start_time;
	int				time;
	int				death;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	mutex_room;
	t_philo			*philo;
}	t_room;

// Destroy

int		destroy_forks(t_room *room);
void	free_all(t_room *room);

// Init

int		assign_forks(t_room *pRoom);
int		init_room(t_room *pRoom, int ac, char **av);
int		init_philos(t_room *pRoom);
int		init(t_room *room, int ac, char **av);

// Print

int		count_figures(long nb);
char	*ft_itoa(int nb);

// Routine

void	*philo_routine(void *var);
void	room_routine(t_room *room);

// Actions

void	took_fork(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	death(t_philo *philo);

// Utils

int		ft_atoi(char *s);
long	get_time(t_philo *philo);
long	get_milliseconds(void);
int		parse_args(int ac, char **av);
int		print_action(t_action action_type, t_philo *philo);
int		print_error(t_error error_type);
int		check_print(t_philo *philo);

#endif