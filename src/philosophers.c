/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:02:05 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/01 15:14:04 by cbijman       ########   odam.nl         */
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

void	*philo_new(t_program *program, int id)
{
	t_philosopher *philo;
	
	philo = ft_calloc(1, sizeof(t_philosopher));
	if (!philo)
		return (NULL);
	philo->id = (id + 1);
	philo->program = program;
	philo->left_fork = id;
	philo->right_fork = (id + 1) % program->nb_of_philos;
	philo->times_eat = 0;
	pthread_mutex_init(&philo->lock, NULL);
	return (philo);
}

void	monitor(t_program *program, t_philosopher **philo)
{
	int	i;

	while (!program->is_dead)
	{
		i = 0;
		if (did_everyone_eat(philo))
		{
			pthread_mutex_lock(&program->dead_lock);
			program->is_dead = true;
			pthread_mutex_unlock(&program->dead_lock);
			return ;
		}
		while (i < program->nb_of_philos)
		{
			pthread_mutex_lock(&program->lock);
			if (ft_gettimewdiff(philo[i]->last_time_eat) > program->time_to_die)
			{
				pthread_mutex_unlock(&program->lock);
				pthread_mutex_lock(&program->dead_lock);
				program->is_dead = true;
				pthread_mutex_unlock(&program->dead_lock);
				ft_log(philo[i], IS_DEAD, false);
				return ;
			}
			pthread_mutex_unlock(&program->lock);
			i++;
		}
		ft_usleep(1);
	}
	return ;
}

int	main(int ac, char **av)
{
	t_program		program;
	t_philosopher	**philo;
	int				i;

	memset(&program, 0, sizeof(t_program));

	//Program initialization
	{
		program.nb_of_philos  = atoi(av[1]);
		program.time_to_die   = atoi(av[2]);
		program.time_to_eat   = atoi(av[3]);
		program.time_to_sleep = atoi(av[4]);
		if (ac == 6)
			program.times_eat = atoi(av[5]);
		program.is_dead		  = false;
		program.time = ft_gettime();
		pthread_mutex_init(&program.lock, NULL);
		pthread_mutex_init(&program.write_lock, NULL);
		pthread_mutex_init(&program.dead_lock, NULL);
	}

	//Allocation
	{
		program.forks = malloc(program.nb_of_philos * sizeof(pthread_mutex_t));
		philo = malloc(program.nb_of_philos * sizeof(t_philosopher));
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

	//philo Initialization
	{
		i = 0;
		while (i < program.nb_of_philos)
		{
			philo[i] = philo_new(&program, i);
			if (!philo[i])
				return (printf("Error creating philosopher exiting...\n"), 0);
			i++;
		}
	}

	//Thread Initialization
	{
		pthread_mutex_lock(&program.lock);
		i = 0;
		while (i < program.nb_of_philos)
		{
			philo[i]->last_time_eat = ft_gettime();
			pthread_create(&philo[i]->thread_id,
				NULL,
				routine,
				philo[i]);
			i++;
		}
		pthread_mutex_unlock(&program.lock);
	}
	
	//Start main thread as monitor thread
	monitor(&program, philo);

	//Joining threads
	{
		i = 0;
		while (i < program.nb_of_philos)
		{
			pthread_join(philo[i]->thread_id, NULL);
			i++;
		}
	}

	//Cleanup
	{
				
	}

	return (printf("Bye!\n"), 0);
}
