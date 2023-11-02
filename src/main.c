/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:02:05 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/02 13:20:52 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_death_to_true(t_program *program)
{
	pthread_mutex_lock(&program->dead_lock);
	program->is_dead = true;
	pthread_mutex_unlock(&program->dead_lock);
}

static void	monitor(t_program *program, t_philosopher **philo)
{
	int	i;

	while (!program->is_dead)
	{
		i = 0;
		if (did_everyone_eat(philo))
			return (set_death_to_true(program));
		while (i < program->nb_of_philos)
		{
			pthread_mutex_lock(&program->lock);
			if (ft_gettimewdiff(philo[i]->last_time_eat) > program->time_to_die)
			{
				pthread_mutex_unlock(&program->lock);
				set_death_to_true(program);
				ft_log(philo[i], IS_DEAD, false);
				return ;
			}
			pthread_mutex_unlock(&program->lock);
			i++;
		}
		usleep(1);
	}
	return ;
}

int	main(int ac, char **av)
{
	t_philosopher	**philos;
	t_program		program;

	memset(&program, 0, sizeof(program));
	if (!is_valid_params(ac, av))
	{
		return (printf(ERR_NOT_ENOUGH_ARGS), EXIT_FAILURE);
	}
	if (!initialize_program(ac, av, &program))
	{
		return (printf(ERR_NOT_ENOUGH_MEMORY), EXIT_FAILURE);
	}
	philos = initialize_philosophers(&program);
	if (!philos)
	{
		return (printf(ERR_NO_PHILO), cleanup_philos(philos), EXIT_FAILURE);
	}
	if (!initialize_forks(&program))
	{
		return (printf(ERR_NO_FORK), cleanup_forks(&program), EXIT_FAILURE);
	}
	monitor(&program, philos);
	cleanup(&program, philos);
	return (EXIT_SUCCESS);
}
