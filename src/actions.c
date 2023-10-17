/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:46:53 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/17 14:55:08 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define RIGHT_FORK 0
#define LEFT_FORK 1

void	lock_fork(t_philosopher *philo, int type)
{
	if (type == RIGHT_FORK)
		pthread_mutex_lock(&philo->program->forks[philo->right_fork]);
	else if (type == LEFT_FORK)
		pthread_mutex_lock(&philo->program->forks[philo->left_fork]);
	log_message_with_timestamp(philo, "has taken a fork\n");
}

bool	p_eat(t_philosopher *philo)
{
	lock_fork(philo, RIGHT_FORK);
	lock_fork(philo, LEFT_FORK);
	log_message_with_timestamp(philo, "is eating\n");
	ft_usleep(philo->program->time_to_eat);
	pthread_mutex_unlock(&philo->program->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->program->forks[philo->right_fork]);
	return (true);
}

bool	p_sleep(t_philosopher *philo)
{
	log_message_with_timestamp(philo, "is sleeping\n");
	ft_usleep(philo->program->time_to_sleep);
	return (true);
}

bool	p_think(t_philosopher *philo)
{
	log_message_with_timestamp(philo, "is thinking\n");
	return (true);
}
