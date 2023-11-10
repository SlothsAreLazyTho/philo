/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/02 11:34:20 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/10 14:50:13 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_program(t_program *program)
{
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->startup_lock);
	pthread_mutex_destroy(&program->lock);
}

void	cleanup_philos(t_philosopher **philos)
{
	int	i;

	if (!philos)
		return ;
	i = 0;
	while (philos[i])
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

	if (!program->forks)
		return ;
	i = 0;
	while (i < program->nb_of_philos)
	{
		pthread_mutex_destroy(&program->forks[i]);
		i++;
	}
	free(program->forks);
}

void	cleanup_threads(t_philosopher **philos)
{
	int	i;

	i = 0;
	if (!philos || !*philos)
		return ;
	while (philos[i])
	{
		pthread_join(philos[i]->thread, NULL);
		i++;
	}
}

void	cleanup(t_program *program, t_philosopher **philos)
{
	cleanup_threads(philos);
	cleanup_philos(philos);
	cleanup_forks(program);
	cleanup_program(program);
}
