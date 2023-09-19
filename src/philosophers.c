/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:02:05 by cbijman       #+#    #+#                 */
/*   Updated: 2023/09/19 17:18:17 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ps_isnumber(char const *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	start_action(t_philosopher *philo, t_philofunc func)
{
	func(philo);
}

void	*thread_func(void *threadctx)
{
	const int		choice = p_odd_or_even();
	t_philosopher	*philo;

	if (!threadctx)
		return (NULL);
	philo = (t_philosopher *) threadctx;
	printf("%d sits at the table\n", philo->id);
	if (choice)
		p_think(philo);
	else
		p_sleep(philo);
	return (philo);
}

void	prepare_table(t_program *program, int size)
{
	size_t	i;
	
	i = 0;
	program->philos = ft_calloc(size + 1, sizeof(t_philosopher));
	while (i < size)
	{
		program->philos[i].id = i;
		pthread_create(&program->philos->thread_id, NULL, thread_func, &program->philos[i]);
		i++;
	}

	i = 0;
	t_philosopher *sop;

	sop = &program->philos[i];
	while (i < size)
	{
		pthread_join(program->philos[i].thread_id, &sop);
		i++;
	}
}

int	safe_atoi(const char *arg)
{
	if (!arg)
		return (0);
	if (!ps_isnumber(arg))
		return (0);
	return (atoi(arg));
}

int	maino(int argc, const char *argv[])
{
	t_program		program;
	struct timeval	val;
	
	gettimeofday(&val, NULL);
	program.number_of_philosophers = safe_atoi(argv[1]);
	program.time_to_die = safe_atoi(argv[2]);
	program.time_to_eat = safe_atoi(argv[3]);
	program.time_to_sleep = safe_atoi(argv[4]);
	program.times_to_eat = safe_atoi(argv[5]);

	program.time = val.tv_usec * 1000;
	program.time += val.tv_sec / 1000;
	print_program_variables(&program);
	prepare_table(&program, program.number_of_philosophers);
	return (0);
}

int	main(void)
{
	const char	*argv[6] = {"./philosophers", "6", "210", "100", "100", "5"};
	return (maino(sizeof(argv) / sizeof(char *), argv));
}