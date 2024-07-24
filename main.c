/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <chsassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:45:09 by chsassi           #+#    #+#             */
/*   Updated: 2024/07/24 09:51:12 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_room	room;

	philo = NULL;
	room = (t_room){0};
	if (!parse_args(ac, av))
		return (0);
	if (!init(&room, ac, av))
		return (0);
	room_routine(&room);
	free_all(&room);
	return (0);
}
