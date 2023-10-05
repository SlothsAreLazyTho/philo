/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_logger.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:55:17 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/05 15:16:36 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_message_with_timestamp(t_philosopher *philo, const char *text)
{
	struct timeval	val;
	time_t			time;

	//pthread_mutex_lock(&philo->program->can_write);
	time = ft_gettime();
	printf("%ld %d %s", time - philo->program->time, philo->id, text);
	//pthread_mutex_unlock(&philo->program->can_write);
}
