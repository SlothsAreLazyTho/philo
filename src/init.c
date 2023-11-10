/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/02 11:32:41 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/10 14:16:29 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philosopher	*new_philosopher(t_program *program, int id)
{
	t_philosopher	*philo;
	static time_t	time = -1;

	if (time == -1)
		time = ft_gettime();
	philo = ft_calloc(1, sizeof(t_philosopher));
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
		return (free(philo), NULL);
	return (philo);
}

t_philosopher	**initialize_philosophers(t_philosopher ***philos,
					t_program *program)
{
	int	i;

	i = 0;
	(*philos) = ft_calloc(program->nb_of_philos + 1, sizeof(t_philosopher));
	if (!(*philos))
		return (NULL);
	while (i < program->nb_of_philos)
	{
		(*philos)[i] = new_philosopher(program, i);
		if (!(*philos)[i])
		{
			cleanup_philos(*philos);
			return (NULL);
		}
		i++;
	}
	return (*philos);
}

bool	initialize_program(int ac, char **av, t_program *program)
{
	program->nb_of_philos = ft_atoi(av[1]);
	program->time_to_die = ft_atoi(av[2]);
	program->time_to_eat = ft_atoi(av[3]);
	program->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		program->times_eat = ft_atoi(av[5]);
	if (program->times_eat > INT32_MAX || program->nb_of_philos > MAX_THREADS)
		return (false);
	program->is_dead = false;
	program->time = ft_gettime();
	program->forks = ft_calloc(program->nb_of_philos, sizeof(pthread_mutex_t));
	if (!program->forks)
		return (false);
	if (!ft_safe_mutex_init(4,
			&program->lock, &program->startup_lock,
			&program->dead_lock, &program->write_lock))
	{
		free(program->forks);
		return (false);
	}
	return (true);
}

bool	initialize_threads(t_program *program,
	t_philosopher **philos, void *(*routine)(void *))
{
	int	i;

	if (!philos || !*philos)
		return (false);
	i = 0;
	pthread_mutex_lock(&program->startup_lock);
	while (philos[i])
	{
		if (pthread_create(&philos[i]->thread, NULL, routine, philos[i]) != 0)
		{
			pthread_mutex_lock(&program->dead_lock);
			program->is_dead = true;
			pthread_mutex_unlock(&program->dead_lock);
			pthread_mutex_unlock(&program->startup_lock);
			return (false);
		}
		i++;
	}
	pthread_mutex_unlock(&program->startup_lock);
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
