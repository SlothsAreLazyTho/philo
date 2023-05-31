/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:30:18 by cbijman       #+#    #+#                 */
/*   Updated: 2023/05/31 18:04:28 by cbijman       ########   odam.nl         */
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

void	*join_table(void *threadctx)
{
	const t_philosopher	*philo = (t_philosopher *) threadctx;
	
	if (p_odd_or_even())
		start_action(philo, p_think);
	else
		start_action(philo, p_sleep);
	return (NULL);
}

void	prepare_table(t_program *program, int size)
{
	static t_table	*table = NULL;
	t_table			*tmp_t;
	t_philosopher	*tmp_p;
	int				statusid;

	while (size--)
	{
		tmp_p = recruit_philosopher(program);
		tmp_t = ps_newlst(tmp_p);
		statusid = pthread_create(&tmp_p->thread_id, NULL, join_table, (void *)tmp_p);
		pthread_join(tmp_p->thread_id, (void *)tmp_p);
		ps_lstadd_back(&table, tmp_t);
	}
	printf("%d philosophers are at the table!\n", ps_lstsize(&table));
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
	const char	*argv[6] = {"./philosophers", "10", "2000",
		"1000", "2000", "5"};
	return (maino(sizeof(argv) / sizeof(char *), argv));
}
