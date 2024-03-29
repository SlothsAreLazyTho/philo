/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:02:05 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/10 14:15:27 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *arg)
{
	t_philosopher	*philo;

	if (!arg)
		return (NULL);
	philo = (t_philosopher *) arg;
	pthread_mutex_lock(&philo->program->startup_lock);
	pthread_mutex_unlock(&philo->program->startup_lock);
	if (philo->id % 2 != 0)
	{
		if (!ft_log(philo, IS_THINKING, true))
			return (NULL);
		ft_usleep(philo, philo->program->time_to_eat / 10);
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

static void	set_death_to_true(t_program *program)
{
	pthread_mutex_lock(&program->dead_lock);
	program->is_dead = true;
	pthread_mutex_unlock(&program->dead_lock);
}

static void	monitor(t_program *program, t_philosopher **philo)
{
	int	i;

	while (true)
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
}

int	main(int ac, char **av)
{
	t_philosopher	**philos;
	t_program		program;

	ft_bzero(&program, sizeof(program));
	if (!is_valid_params(ac, av))
		return (printf(ERR_NOT_ENOUGH_ARGS), EXIT_FAILURE);
	if (!initialize_program(ac, av, &program))
		return (printf(ERR_NOT_ENOUGH_MEMORY),
			cleanup_program(&program), EXIT_FAILURE);
	if (!initialize_forks(&program))
		return (printf(ERR_NO_FORK),
			cleanup_program(&program), cleanup_forks(&program), EXIT_FAILURE);
	if (!initialize_philosophers(&philos, &program))
		return (printf(ERR_NO_PHILO),
			cleanup_program(&program), cleanup_forks(&program), EXIT_FAILURE);
	if (!initialize_threads(&program, philos, routine))
		return (printf(ERR_W_THREADS), cleanup(&program, philos), EXIT_FAILURE);
	monitor(&program, philos);
	cleanup(&program, philos);
	return (EXIT_SUCCESS);
}
