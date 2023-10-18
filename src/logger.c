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

void	ft_log(t_philosopher *philo, const char *text)
{
	pthread_mutex_lock(&philo->program->write_lock);
	printf("%ld %d %s", ft_gettime() - philo->program->time, philo->id, text);
	pthread_mutex_unlock(&philo->program->write_lock);
}
