#include "philo.h"

int	start_eating(t_room *pRoom)
{

	pthread_mutex_init(pRoom->forks, NULL);
	pthread_mutex_init(&pRoom->print, NULL);
	pthread_mutex_init(pRoom->forks, NULL);

	// Guardare se le forchette a sx e a dx sono libere
	// se sono libere mangi
	print_action(EATING, pRoom);
	return (0);

}

void	*philo_routine(void *var)
{
	t_room	*ptr;

	(void)var;
	ptr = NULL;
	pthread_mutex_init(&ptr->print, NULL);
	pthread_mutex_lock(&ptr->print);
	pthread_mutex_unlock(&ptr->print);
	start_eating(ptr);
	// dormi
	// pensi
	// se muore, esci
	return (0);
}

