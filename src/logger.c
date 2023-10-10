/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_logger.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:55:17 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/10 14:12:27 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_message_with_timestamp(t_philosopher *philo, const char *text)
{
	pthread_mutex_lock(&philo->program->can_write);
	printf("%ld %d %s", ft_gettime() - philo->program->time, philo->id, text);
	pthread_mutex_unlock(&philo->program->can_write);
}
