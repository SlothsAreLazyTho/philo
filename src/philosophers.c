/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:02:05 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/10 14:51:58 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *threadctx);

void	print_program_variables(t_program *program)
{
	printf("nb_of_philos: %d,\n\
time_to_die: %dms,\n\
time_to_eat: %dms,\n\
time_to_sleep: %dms,\n\
number_of_times_each_philosopher_must_eat [Optional]: %d\n",
		program->nb_of_philos,
		program->time_to_die,
		program->time_to_eat,
		program->time_to_sleep,
		program->times_eat);
}

bool	loop_through_all_philos(t_program *program, void *(*f)(t_program *, t_philosopher *, int), t_philosopher *obj)
{
	size_t	i;

	i = 0;
	if (!obj)
		return (false);
	while (i < program->nb_of_philos)
	{
		if (!f(program, &obj[i], i))
			return (false);
		i++;
	}
	return (true);
}

void	*philo_new(t_program *program, t_philosopher *philo, int id)
{
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->program = program;
	philo->left_fork = id;
	philo->right_fork = (id + 1) % program->nb_of_philos;
	pthread_mutex_init(&philo->eat_lock, NULL);
	pthread_create(&philo->thread_id, NULL, routine, philo);
	return (philo);
}

void	*routine(void *threadctx)
{
	t_philosopher	*philo;

	if (!threadctx)
		return (NULL);
	philo = (t_philosopher *) threadctx;
	if (philo->id % 2)
		p_sleep(philo);
	else
		p_eat(philo);
	return (NULL);
}

int	safe_atoi(const char *arg)
{
	if (!arg)
		return (0);
	if (!ft_isnumber(arg))
		return (0);
	return (atoi(arg));
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

bool	fork_init(t_program	*program)
{
	size_t	i;

	i = 0;
	program->forks = malloc(program->nb_of_philos * sizeof(pthread_mutex_t));
	if (!program->forks)
		return (false);
	while (i < program->nb_of_philos)
	{
		printf("Fork: %d\n", pthread_mutex_init(&program->forks[i], NULL));
		i++;
	}
	return (i == program->nb_of_philos);
}

void	philo_init(t_program *program, t_philosopher **philo)
{
	(*philo) = ft_calloc(program->nb_of_philos, sizeof(t_philosopher));
	if (!*philo)
		return (exit(1)); //Make checks
	loop_through_all_philos(program, philo_new, *philo);
}

int	maino(int ac, const char **av)
{
	t_program		*program;
	t_philosopher	*philosophers;
	size_t			i;

	program_init(&program, ac, av);
	fork_init(program);
	philo_init(program, &philosophers);

	i = 0;
	while (i < program->nb_of_philos)
	{
		pthread_join(philosophers[i].thread_id, NULL);
		i++;
	}
	return (0);
}

int	main(void)
{
	const char	*argv[6] = {
		"./philosophers",
		"4",
		"410", //Time to die
		"200", //Time to sleep
		"200", //Time to eat
		"5"};

	return (maino(sizeof(argv) / sizeof(char *), argv));
}
