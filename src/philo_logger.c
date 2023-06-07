/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_logger.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:55:17 by cbijman       #+#    #+#                 */
/*   Updated: 2023/06/07 18:06:55 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_message_with_timestamp(t_philosopher *philo, const char *text)
{
	//struct timeval	val;

	//gettimeofday(&val, 0x0);
	printf("%ld %d %s", 0,
		philo->id,
		text);
}
