/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   logger.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:55:17 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/18 17:46:11 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Prints message unless a philo died.
/// @param philo Philosopher in thread
/// @param text whatever you want it to be buddy.
bool	ft_log(t_philosopher *philo, const char *text)
{
	pthread_mutex_lock(&philo->program->write_lock);
	if (ft_gettimediffl(ft_gettime(), philo->last_time_eat) > philo->program->time_to_die)
	{
		printf("Philo %d died.", philo->id);
		return (false);
	}
	printf("%ld %d %s", ft_gettime() - philo->program->time, philo->id, text);
	pthread_mutex_unlock(&philo->program->write_lock);
	return (true);
}
