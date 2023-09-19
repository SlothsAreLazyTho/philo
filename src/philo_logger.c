/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_logger.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:55:17 by cbijman       #+#    #+#                 */
/*   Updated: 2023/09/19 17:14:42 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_message_with_timestamp(t_philosopher *philo, const char *text)
{
	struct timeval	val;
	ssize_t			time;

	gettimeofday(&val, NULL);
	time = val.tv_usec / 1000;
	time += val.tv_sec * 1000;
	printf("%ld %d %s", philo->program->time - time, philo->id, text);
}
