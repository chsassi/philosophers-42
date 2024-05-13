/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:45:09 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/06 17:28:07 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(void)
{
	// t_room	room;
	// t_philo	*philo;

	// philo = NULL;
	// room = (t_room){0};
	// if (!parse_args(ac, av))
	// 	return (0);
	// init_room(&room, ac, av);
	// init_philos(&room);
	get_ms();
}

// typedef struct x
// {
// 	int i;
// 	pthread_mutex_t stampa;
// 	pthread_mutex_t num;
// } t_x;


// void	*routine(void *x)
// {	
// 	t_x *var;

// 	var = (t_x *)x;
// 	pthread_mutex_lock(&var->num);
// 	while (var->i < 1000)
// 	{
// 		pthread_mutex_unlock(&var->num);
// 		pthread_mutex_lock(&var->stampa);
// 		pthread_mutex_lock(&var->num);
// 		printf("---- %i\n",var->i);
// 		var->i+=1;
// 		pthread_mutex_unlock(&var->num);
// 		pthread_mutex_unlock(&var->stampa);

// 	}
// 	return (0);
// }

// int	main()
// {
// 	pthread_t	*threadOne;
// 	t_x x;
// 	x.i = 0;
// 	pthread_mutex_init(&x.stampa, NULL);
// 	pthread_mutex_init(&x.num, NULL);
// 	threadOne = malloc(100 * sizeof(pthread_t));
// 	int count = 0;
// 	while(count < 3)
// 	{
// 		pthread_create(&threadOne[count], NULL, &routine, (void *)&x);
// 		count++;
// 	}
// 	while(1)
// 	{
// 		pthread_mutex_lock(&x.stampa);
// 		pthread_mutex_lock(&x.num);
// 		printf("%i\n",x.i);
// 		x.i++;
// 		if (x.i > 1000)
// 			break;
// 		pthread_mutex_unlock(&x.stampa);
// 		pthread_mutex_unlock(&x.num);
// 	}
// }
