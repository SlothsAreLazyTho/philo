/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/02 11:34:20 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/02 14:01:13 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_program(t_program *program)
{
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->lock);
}

void	cleanup_philos(t_philosopher **philos)
{
	int	i;
	int	maxc;

	i = 0;
	maxc = (*philos)->program->nb_of_philos;
	while (i < maxc)
	{
		pthread_mutex_destroy(&philos[i]->lock);
		free(philos[i]);
		i++;
	}
	free(philos);
}

void	cleanup_forks(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->nb_of_philos)
	{
		pthread_mutex_destroy(&program->forks[i]);
		i++;
	}
	free(program->forks);
}

void	cleanup_threads(t_program *program, t_philosopher **philos)
{
	int	i;

	i = 0;
	while (i < program->nb_of_philos)
	{
		pthread_join(philos[i]->thread, NULL);
		i++;
	}
}

void	cleanup(t_program *program, t_philosopher **philos)
{
	cleanup_threads(program, philos);
	cleanup_forks(program);
	cleanup_philos(philos);
	cleanup_program(program);
}
