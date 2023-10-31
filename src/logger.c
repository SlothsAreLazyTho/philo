/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   logger.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:55:17 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/31 14:59:50 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Prints message unless a philo died.
/// @param philo Philosopher in thread
/// @param text whatever you want it to be buddy.
bool	ft_log(t_philosopher *philo, const char *text)
{
	pthread_mutex_lock(&philo->program->write_lock);
	pthread_mutex_lock(&philo->program->dead_lock);
	if (philo->program->is_dead)
	{
		pthread_mutex_unlock(&philo->program->write_lock);
		pthread_mutex_unlock(&philo->program->dead_lock);
		return (false);
	}
	printf("%ld %d %s", ft_gettime() - philo->program->time, philo->id, text);
	pthread_mutex_unlock(&philo->program->write_lock);
	pthread_mutex_unlock(&philo->program->dead_lock);
	return (true);
}
