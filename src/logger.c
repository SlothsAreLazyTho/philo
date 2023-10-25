/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   logger.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:55:17 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/25 16:00:42 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


bool	is_philo_dood(t_philosopher *philo)
{
	pthread_mutex_t	lock;

	
}

/// @brief Prints message unless a philo died.
/// @param philo Philosopher in thread
/// @param text whatever you want it to be buddy.
bool	ft_log(t_philosopher *philo, const char *text)
{
	time_t	time;

	pthread_mutex_lock(&philo->program->write_lock);
	time = ft_gettime() - philo->program->time;
	//printf("Philo %d => %ld, How much between last time eat & dead? ? = %ld, %ld\n", philo->id, philo->last_time_eat,
	//	ft_gettimewdiff(philo->last_time_eat) > philo->program->time_to_die, ft_gettimewdiff(philo->last_time_eat));
	
	if (ft_gettimewdiff(philo->last_time_eat) > philo->program->time_to_die)
	{
		printf("%ld %d died\n", time, philo->id);
		return (pthread_mutex_unlock(&philo->program->write_lock), false);
	}
	printf("%ld %d %s", time, philo->id, text);
	pthread_mutex_unlock(&philo->program->write_lock);
	return (true);
}
