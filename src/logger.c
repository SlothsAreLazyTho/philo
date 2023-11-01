/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   logger.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:55:17 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/01 15:11:06 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	did_everyone_eat(t_philosopher **philo)
{
	t_program	*program;
	int			i;

	if (!(*philo))
		return (false);
	i = 0;
	program = (*philo)->program;
	pthread_mutex_lock(&program->lock);
	if (program->times_eat == 0)
	{
		pthread_mutex_unlock(&program->lock);
		return (false);
	}
	while (philo[i] && philo[i]->times_eat >= program->times_eat)
		i++;
	pthread_mutex_unlock(&program->lock);
	return (program->nb_of_philos == i);
}

bool	did_anyone_die(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->program->dead_lock);
	if (philo->program->is_dead == true)
	{
		pthread_mutex_unlock(&philo->program->dead_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->program->dead_lock);
	return (false);
}

/// @brief Prints message unless a philo died.
/// @param philo Philosopher in thread
/// @param text whatever you want it to be buddy.
bool	ft_log(t_philosopher *philo, const char *text, bool check_death)
{
	pthread_mutex_lock(&philo->program->write_lock);
	if (did_anyone_die(philo) && check_death)
		return (pthread_mutex_unlock(&philo->program->write_lock), false);
	printf("%ld %d %s\n", ft_gettime() - philo->program->time, philo->id, text);
	return (pthread_mutex_unlock(&philo->program->write_lock), true);
}
