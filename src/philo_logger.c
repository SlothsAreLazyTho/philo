/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_logger.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:55:17 by cbijman       #+#    #+#                 */
/*   Updated: 2023/09/20 10:43:37 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_message_with_timestamp(t_philosopher *philo, const char *text)
{
	struct timeval	val;
	time_t			time;

	time = ft_gettime();
	printf("%ld %d %s", time - philo->program->time, philo->id, text);
}
