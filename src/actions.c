/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:46:53 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/18 17:52:21 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define RIGHT_FORK 0
#define LEFT_FORK 1

void	lock_forks(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->program->forks[philo->left_fork]);
	ft_log(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->program->forks[philo->right_fork]);
	ft_log(philo, "has taken a fork\n");
}

void	drop_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->program->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->program->forks[philo->left_fork]);
}

bool	p_eat(t_philosopher *philo)
{
	lock_forks(philo);
	pthread_mutex_lock(&philo->lock);
	if (!ft_log(philo, "is eating\n"))
		return (false);
	philo->last_time_eat = ft_gettime();
	ft_usleep(philo->program->time_to_eat);
	pthread_mutex_unlock(&philo->lock);
	drop_forks(philo);
	return (true);
}

bool	p_sleep(t_philosopher *philo)
{
	if (!ft_log(philo, "is sleeping\n"))
		return (false);
	ft_usleep(philo->program->time_to_sleep);
	return (true);
}

bool	p_think(t_philosopher *philo)
{
	if (!ft_log(philo, "is thinking\n"))
		return (false);
	return (true);
}
