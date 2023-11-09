/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/02 11:32:41 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/09 15:19:08 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philosopher	*new_philosopher(t_program *program, int id)
{
	t_philosopher	*philo;
	static time_t	time = -1;

	if (time == -1)
		time = ft_gettime();
	philo = malloc(sizeof(t_philosopher));
	if (!philo)
		return (NULL);
	philo->program = program;
	philo->id = (id + 1);
	philo->thread = NULL;
	philo->left_fork = id;
	philo->right_fork = (id + 1) % program->nb_of_philos;
	philo->times_eat = 0;
	philo->last_time_eat = time;
	if (pthread_mutex_init(&philo->lock, NULL) != 0)
		return (NULL);
	return (philo);
}

int	my_pthread_create(
	pthread_t *a, const pthread_attr_t *b, void *(*c)(void *), void *d)
{
	static int	i = 0;

	i++;
	if (i > 2)
		return (1);
	return (pthread_create(a, b, c, d));
}

t_philosopher	**initialize_philosophers(t_program *program)
{
	t_philosopher	**philos;
	int				i;

	i = 0;
	philos = malloc(program->nb_of_philos * sizeof(t_philosopher));
	if (!philos)
		return (NULL);
	memset(philos, 0, program->nb_of_philos * sizeof(t_philosopher));
	while (i < program->nb_of_philos)
	{
		philos[i] = new_philosopher(program, i);
		if (!philos[i])
			return (cleanup_philos(philos), NULL);
		i++;
	}
	return (philos);
}

bool	initialize_program(int ac, char **av, t_program *program)
{
	program->nb_of_philos = ft_atoi(av[1]);
	if (program->nb_of_philos > MAX_THREADS)
		return (false);
	program->time_to_die = ft_atoi(av[2]);
	program->time_to_eat = ft_atoi(av[3]);
	program->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		program->times_eat = ft_atoi(av[5]);
	program->is_dead = false;
	program->time = ft_gettime();
	program->forks = malloc(program->nb_of_philos * sizeof(pthread_mutex_t));
	if (!program->forks)
		return (false);
	if (program->times_eat > INT32_MAX)
		return (free(program->forks), false);
	if (pthread_mutex_init(&program->lock, NULL) != 0)
		return (free(program->forks), cleanup_program(program), false);
	if (pthread_mutex_init(&program->dead_lock, NULL) != 0)
		return (free(program->forks), cleanup_program(program), false);
	if (pthread_mutex_init(&program->write_lock, NULL) != 0)
		return (free(program->forks), cleanup_program(program), false);
	return (true);
}

bool	initialize_threads(t_program *program,
	t_philosopher **philos, void *(*routine)(void *))
{
	int	i;

	if (!philos || !*philos)
		return (false);
	i = 0;
	pthread_mutex_lock(&program->lock);
	while (philos[i])
	{
		if (my_pthread_create(&philos[i]->thread, NULL,
				routine, philos[i]) != 0)
		{
			program->is_dead = true; //Set death to true.
			pthread_mutex_unlock(&program->lock);
			return (false);
		}
		i++;
	}
	pthread_mutex_unlock(&program->lock);
	return (true);
}

bool	initialize_forks(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->nb_of_philos)
	{
		if (pthread_mutex_init(&program->forks[i], NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}
