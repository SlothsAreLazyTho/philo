/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_threads.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:05:03 by cbijman       #+#    #+#                 */
/*   Updated: 2023/06/07 18:05:06 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "pthread.h"


void	thread_func(void *threadctx)
{
	const t_philosopher	*philo = (t_philosopher *)threadctx;
	const int			choice = p_odd_or_even();

	printf("%d sits at the table\n", philo->id);
	if (choice)
		start_action(philo, p_think);
	else
		start_action(philo, p_sleep);
}

void	start_routine(t_philosopher *philo)
{
	const int		status = pthread_create(&philo->thread_id,
			NULL, thread_func, philo);
	struct timeval	val;

	gettimeofday(&val, NULL);
	philo->last_time_eat = 0L;
	philo->time_of_born = val.tv_usec;
}
