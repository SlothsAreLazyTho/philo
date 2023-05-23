/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:30:18 by cbijman       #+#    #+#                 */
/*   Updated: 2023/05/23 20:20:31 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

t_philosopher	*recruit_philosopher(t_program *program)
{
	static int		size = 1;
	t_philosopher	*person;

	person = ft_calloc(1, sizeof(t_philofunc));
	if (!person)
		return (NULL);
	person->id = size++;
	person->program = program;
	return (person);
}

void	start_action(t_philosopher *philo, t_philofunc func)
{
	__THROW_NOT_IMPLEMENTED();
}

void	join_table(t_philosopher *philo, pthread_t *t)
{
	
	__THROW_NOT_IMPLEMENTED();
}

void	prepare_table(t_program *program, int size)
{
	static t_table			*table = NULL;
	t_table					*tmp_t;
	t_philosopher			*tmp_p;

	while (size--)
	{
		tmp_p = recruit_philosopher(program);
		tmp_t = ps_newlst(tmp_p);
		ps_lstadd_back(&table, tmp_t);
	}
	printf("%d philosophers are at the table!\n", ps_lstsize(&table));
	pthread_create()

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
	program.number_of_times_each_philosopher_must_eat = safe_atoi(argv[5]);
	printf("number_of_philosophers: %dms,\n\
time_to_die: %dms,\n\
time_to_eat: %dms,\n\
time_to_sleep: %dms,\n\
number_of_times_each_philosopher_must_eat [Optional]: %d\n", 
		program.number_of_philosophers, 
		program.time_to_die, 
		program.time_to_eat,
		program.time_to_sleep, 
		program.number_of_times_each_philosopher_must_eat);
	prepare_table(&program, program.number_of_philosophers);
	return (0);
}

int	main(void)
{
	const char	*argv[6] = {"./philosophers", "10", "2000",
		"1000", "2000", "5"};

	return (maino(sizeof(argv) / sizeof(char *), argv));
}
