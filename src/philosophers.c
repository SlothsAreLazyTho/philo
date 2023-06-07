/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:02:05 by cbijman       #+#    #+#                 */
/*   Updated: 2023/06/07 18:07:13 by cbijman       ########   odam.nl         */
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

void	*ft_calloc(int count, int size)
{
	void	*content;

	content = malloc(count * size);
	if (!content)
		return (NULL);
	memset(content, 0, size);
	return (content);
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

void	prepare_table(t_program *program, int size)
{
	size_t			i;

	i = 0;
	program->philos = ft_calloc(size + 1, sizeof(t_philosopher *));
	while (i < size)
	{
		program->philos[i] = recruit_philosopher(program);
		if (!program->philos[i])
			return ;
		start_routine(program->philos[i]);
		i++;
	}

	for (int i = 0; program->philos[i]; i++)
		pthread_join(program->philos[i]->thread_id, program->philos[i]);
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
	t_program	program;

	program.number_of_philosophers = safe_atoi(argv[1]);
	program.time_to_die = safe_atoi(argv[2]);
	program.time_to_eat = safe_atoi(argv[3]);
	program.time_to_sleep = safe_atoi(argv[4]);
	program.times_to_eat = safe_atoi(argv[5]);
	print_program_variables(&program);
	prepare_table(&program, program.number_of_philosophers);
	return (0);
}

int	main(void)
{
	const char	*argv[6] = {"./philosophers", "2", "2000",
		"1000", "2000", "5"};
	return (maino(sizeof(argv) / sizeof(char *), argv));
}
