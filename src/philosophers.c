/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:02:05 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/18 17:52:59 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *threadctx)
{
	t_philosopher	*philo = (t_philosopher *) threadctx;

	pthread_mutex_lock(&philo->program->lock);
	pthread_mutex_unlock(&philo->program->lock);
	if (philo->id % 2 != 0)
	{
		if (!p_think(philo))
			return (NULL);
		ft_usleep(philo->program->time_to_eat / 2);
	}
	while (true)
	{
		if (!p_eat(philo))
			return (NULL);
		if (!p_sleep(philo))
			return (NULL);
		if (!p_think(philo))
			return (NULL);
	}
	return (philo);
}

void	*philo_new(t_program *program, int id)
{
	t_philosopher *philo;
	
	philo = malloc(sizeof(t_philosopher));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->program = program;
	philo->left_fork = id;
	philo->right_fork = (id + 1) % program->nb_of_philos;
	pthread_mutex_init(&philo->lock, NULL);
	return (philo);
}

int	main(void)
{
	int ac = 6;
	const char	*av[6] = { "./philosophers",
		"6",
		"310", //Time to die
		"100", //Time to sleep
		"100", //Time to eat
		"5"}; //Optional: times to eat

	t_program		program;
	t_philosopher	**philosophers;
	size_t			i;

	memset(&program, 0, sizeof(t_program));

	//Program initialization
	{
		program.nb_of_philos = atoi(av[1]);
		program.time_to_die = atoi(av[2]);
		program.time_to_eat = atoi(av[3]);
		program.time_to_sleep = atoi(av[4]);
		program.times_eat = atoi(av[5]);
		program.time = ft_gettime();
		pthread_mutex_init(&program.lock, NULL);
		pthread_mutex_init(&program.write_lock, NULL);
	}

	//Allocation
	{
		program.forks = malloc(program.nb_of_philos * sizeof(pthread_mutex_t));
		philosophers = malloc(program.nb_of_philos * sizeof(t_philosopher));
	}

	//Forks initilization
	{
		i = 0;
		while (i < program.nb_of_philos)
		{
			if (pthread_mutex_init(&program.forks[i], NULL) != 0)
				return (printf("Forks cannot be initializated\n"), 0);
			i++;
		}
	}

	//Philosophers Initialization
	{
		i = 0;
		while (i < program.nb_of_philos)
		{
			philosophers[i] = philo_new(&program, i);
			if (!philosophers[i])
				return (printf("Error creating philosopher exiting...\n"), 0);
			i++;
		}
	}

	//Thread Initilizatoin
	{
		pthread_mutex_lock(&program.lock);
		i = 0;
		while (i < program.nb_of_philos)
		{
			philosophers[i]->last_time_eat = ft_gettime();
			pthread_create(&philosophers[i]->thread_id,
				NULL,
				routine,
				philosophers[i]);
			i++;
		}
		pthread_mutex_unlock(&program.lock);
	}
	
	//Joining threads
	{
		i = 0;
		while (i < program.nb_of_philos)
		{
			pthread_join(philosophers[i]->thread_id, NULL);
			i++;
		}
	}
	return (0);
}
