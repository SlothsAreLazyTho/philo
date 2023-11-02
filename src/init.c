/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/02 11:32:41 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/02 12:38:26 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stddef.h>

static void	*routine(void *threadctx)
{
	t_philosopher	*philo;

	if (!threadctx)
		return (NULL);
	philo = (t_philosopher *) threadctx;
	pthread_mutex_lock(&philo->program->lock);
	pthread_mutex_unlock(&philo->program->lock);
	if (philo->id % 2 != 0)
	{
		ft_log(philo, IS_THINKING, false);
		ft_usleep(philo->program->time_to_eat / 10);
	}
	while (true)
	{
		if (!p_eat(philo))
			return (NULL);
		if (!p_sleep(philo))
			return (NULL);
		if (!ft_log(philo, IS_THINKING, true))
			return (NULL);
	}
	return (philo);
}

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

t_philosopher	**initialize_philosophers(t_program *program)
{
	t_philosopher	**philos;
	int				i;

	i = 0;
	philos = malloc(program->nb_of_philos * sizeof(t_philosopher));
	if (!philos)
		return (NULL);
	pthread_mutex_lock(&program->lock);
	while (i < program->nb_of_philos)
	{
		philos[i] = new_philosopher(program, i);
		if (!philos[i])
			return (NULL);
		i++;
	}
	i = 0;
	while (i < program->nb_of_philos)
	{
		if (pthread_create(&philos[i]->thread, NULL, routine, philos[i]) != 0)
			return (NULL);
		i++;
	}
	pthread_mutex_unlock(&program->lock);
	return (philos);
}

bool	initialize_program(int ac, char **av, t_program *program)
{
	program->nb_of_philos = atoi(av[1]);
	program->time_to_die = atoi(av[2]);
	program->time_to_eat = atoi(av[3]);
	program->time_to_sleep = atoi(av[4]);
	if (ac == 6)
		program->times_eat = atoi(av[5]);
	program->is_dead = false;
	program->time = ft_gettime();
	program->forks = ft_calloc(program->nb_of_philos, sizeof(pthread_mutex_t));
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
