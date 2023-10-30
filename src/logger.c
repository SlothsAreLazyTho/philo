/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   logger.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:55:17 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/30 15:21:05 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


bool	is_philo_dood(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->program->dead_lock);
	
	if (ft_gettimewdiff(philo->last_time_eat) > philo->program->time_to_die)
	{
		printf("%ld %d died\n", time, philo->id);
		return (pthread_mutex_unlock(&philo->program->dead_lock), false);
	}
	return (pthread_mutex_unlock(&philo->program->dead_lock), true);
}

/// @brief Prints message unless a philo died.
/// @param philo Philosopher in thread
/// @param text whatever you want it to be buddy.
bool	ft_log(t_philosopher *philo, const char *text)
{
	pthread_mutex_lock(&philo->program->write_lock);
	if (is_philo_dood(philo))
		return (false);
	printf("%ld %d %s", ft_gettime() - philo->program->time, philo->id, text);
	pthread_mutex_unlock(&philo->program->write_lock);
	return (true);
}
