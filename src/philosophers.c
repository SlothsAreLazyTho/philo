/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:02:05 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/03 15:34:53 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *threadctx);

void	print_program_variables(t_program *program)
{
	printf("number_of_philosophers: %d,\n\
time_to_die: %dms,\n\
time_to_eat: %dms,\n\
time_to_sleep: %dms,\n\
number_of_times_each_philosopher_must_eat [Optional]: %d\n",
		program->number_of_philosophers,
		program->time_to_die,
		program->time_to_eat,
		program->time_to_sleep,
		program->times_to_eat);
}

bool	loop_through_all_philos(t_program *program, void *(*f)(t_program *, t_philosopher *), t_philosopher *obj)
{
	size_t	i;

	i = 0;
	if (!obj)
		return (false);
	while (i < program->number_of_philosophers)
	{
		if (!f(program, &obj[i]))
			return (false);
		obj[i].id = i;
		i++;
	}
	return (true);	
}

void	*philo_new(t_program *program, t_philosopher *philo)
{
	if (!philo)
		return (NULL);
	philo->program = program;
	pthread_mutex_init(&philo->left_fork, NULL);
	pthread_mutex_init(&philo->right_fork, NULL);
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
	printf("%d sits at the table\n", philo->id);
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

void	cool(t_program *program, t_philosopher **philos)
{
	*philos = ft_calloc(program->number_of_philosophers, sizeof(t_philosopher));
}

int	maino(int argc, const char *argv[])
{
	t_program		*program;
	t_philosopher	*philosophers;

	struct timeval	val;
	size_t			i;
	
	program = ft_calloc(1, sizeof(t_program));
	program->number_of_philosophers = safe_atoi(argv[1]);
	program->time_to_die = safe_atoi(argv[2]);
	program->time_to_eat = safe_atoi(argv[3]);
	program->time_to_sleep = safe_atoi(argv[4]);
	program->times_to_eat = safe_atoi(argv[5]);
	program->time = ft_gettime();
	//print_program_variables(program);
	
	cool(program, &philosophers);
	loop_through_all_philos(program, philo_new, philosophers);
	
	i = 0;
	while (i < program->number_of_philosophers)
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
