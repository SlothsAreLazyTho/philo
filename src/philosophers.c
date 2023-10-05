/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:02:05 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/05 15:20:38 by cbijman       ########   odam.nl         */
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
		obj[i].id = i;
		i++;
	}
	return (true);	
}

void	*philo_new(t_program *program, t_philosopher *philo, int id)
{
	if (!philo)
		return (NULL);
	philo->program = program;
	philo->left_fork = id;
	philo->right_fork = (id + 1) % program->nb_of_philos;
	pthread_create(&philo->thread_id, NULL, routine, philo);
	return (philo);
}

void	philosleep(t_program *program, unsigned int time)
{
	int seconds;
	
	seconds = 0;
	while (seconds < time)
	{
		usleep(1000);
		seconds++;
	}
}

void	start_action(t_philosopher *philo, t_philofunc func)
{
	func(philo);
}

void	*routine(void *threadctx)
{
	t_philosopher	*philo;

	if (!threadctx)
		return (NULL);
	philo = (t_philosopher *) threadctx;
	//printf("%d sits at the table\n", philo->id);
	if (philo->id % 2)
		p_think(philo);
	else
		p_sleep(philo);
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
	
	obj = ft_calloc(1, sizeof(t_program));
	if (!obj)
		return (exit(1));
	obj->nb_of_philos = safe_atoi(argv[1]);
	obj->time_to_die = safe_atoi(argv[2]);
	obj->time_to_eat = safe_atoi(argv[3]);
	obj->time_to_sleep = safe_atoi(argv[4]);
	obj->times_eat = safe_atoi(argv[5]);
	obj->time = ft_gettime();
	
	pthread_mutex_init(&obj->can_write, NULL);

	*program = obj;
}

bool	fork_init(t_program	*program)
{
	size_t	i;

	i = 0;
	program->forks = malloc(program->nb_of_philos * sizeof(pthread_mutex_t));
	if (!program->forks)
		return (false);
	while (i < program->nb_of_philos && pthread_mutex_init(&program->forks[i], NULL) == 0)
		i++;
	return (i == program->nb_of_philos);
}

void	philo_init(t_program *program, t_philosopher **philo)
{
	(*philo) = ft_calloc(program->nb_of_philos, sizeof(t_philosopher));
	if (!*philo)
		return (exit(1));
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
		"5",
		"210",
		"100",
		"100",
		"5"};

	return (maino(sizeof(argv) / sizeof(char *), argv));
}
