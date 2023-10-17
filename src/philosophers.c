/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:02:05 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/17 14:56:46 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *threadctx)
{
	t_philosopher	*philo;

	if (!threadctx)
		return (NULL);
	philo = (t_philosopher *) threadctx;
	if (philo->id % 2 != 0)
	{
		while (true)
		{
			if (!p_think(philo))
				return (NULL);
			if (!p_eat(philo))
				return (NULL);
			if (!p_sleep(philo))
				return (NULL);
		}
	}
	else
	{
		while (true)
		{
			if (!p_eat(philo))
				return (NULL);
			if (!p_sleep(philo))
				return (NULL);
			if (!p_think(philo))
				return (NULL);
		}
	}
	return (philo);
}

void	*philo_new(t_program *program, int id)
{
	t_philosopher *philo;
	
	philo = malloc(sizeof(t_philosopher));
	if (!philo)
		return (NULL);
	philo->id = (id + 1);
	philo->program = program;
	philo->left_fork = id;
	philo->right_fork = (id + 1) % program->nb_of_philos;
	pthread_create(&philo->thread_id, NULL, routine, philo);
	return (philo);
}

void	program_init(t_program **program, int argc, const char **argv)
{
	t_program	*obj;
	
	obj = malloc(sizeof(t_program));
	if (!obj)
		return (exit(1));
	obj->nb_of_philos = atoi(argv[1]);
	obj->time_to_die = atoi(argv[2]);
	obj->time_to_eat = atoi(argv[3]);
	obj->time_to_sleep = atoi(argv[4]);
	obj->times_eat = atoi(argv[5]);
	obj->time = ft_gettime();
	
	pthread_mutex_init(&obj->can_write, NULL);
	pthread_mutex_init(&obj->can_eat, NULL);
	*program = obj;
}

int	main(void)
{
	int ac = 6;
	const char	*av[6] = { "./philosophers",
		"5",
		"310", //Time to die
		"100", //Time to sleep
		"100", //Time to eat
		"5"}; //Optional: times to eat
	
	t_program		*program;
	t_philosopher	**philosophers;
	size_t			i;

	//Redo initialization
	program_init(&program, ac, av);

	//Forks initilization
	{
		i = 0;
		program->forks = malloc(program->nb_of_philos * sizeof(pthread_mutex_t));
		if (!program->forks)
			return (0);
		while (i < program->nb_of_philos)
		{
			if (pthread_mutex_init(&program->forks[i], NULL) != 0)
				return (printf("Forks cannot be initializated\n"), 0);
			i++;
		}
	}

	//Philosophers Initialization
	{
		i = 0;
		philosophers = malloc(program->nb_of_philos * sizeof(t_philosopher));
		if (!philosophers)
			return (0);
		while (i < program->nb_of_philos)
		{
			philosophers[i] = philo_new(program, i);
			if (!philosophers[i])
				return (printf("Error creating philosopher exiting...\n"), 0);
			i++;
		}
	}
	
	//Redo initiailizaition

	i = 0;
	while (i < program->nb_of_philos)
	{
		pthread_join(philosophers[i]->thread_id, NULL);
		i++;
	}
	return (0);
}
