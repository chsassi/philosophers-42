#include "philo.h"

int	start_eating(t_room *pRoom)
{
	pthread_mutex_init(&pRoom->forks, NULL);
	
	// se il philo ha le due forks libere, mangia
	// Guardare se le forchette a sx e a dx sono libere
	// se sono libere mangi
		print_action(EATING);
}

void	*philo_routine(void *var)
{
	t_room	*ptr;

	pthread_mutex_init(&ptr->print, NULL);
	start_eating(ptr);
	// dormi
	// pensi
	// se muore, esci
	return (0);
}

