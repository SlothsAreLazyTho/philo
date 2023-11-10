/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:46:53 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/10 14:05:44 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->program->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->program->forks[philo->left_fork]);
}

void	lock_forks(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->program->forks[philo->left_fork]);
	if (!ft_log(philo, TAKES_A_FORK, true))
	{
		pthread_mutex_unlock(&philo->program->forks[philo->left_fork]);
		return ;
	}
	if (philo->program->nb_of_philos == 1)
	{
		ft_usleep(philo, philo->program->time_to_die + 42069);
		return ;
	}
	pthread_mutex_lock(&philo->program->forks[philo->right_fork]);
	if (!ft_log(philo, TAKES_A_FORK, true))
	{
		drop_forks(philo);
		return ;
	}
}

bool	p_eat(t_philosopher *philo)
{
	lock_forks(philo);
	pthread_mutex_lock(&philo->program->lock);
	philo->times_eat++;
	philo->last_time_eat = ft_gettime();
	pthread_mutex_unlock(&philo->program->lock);
	if (!ft_log(philo, IS_EATING, true))
	{
		drop_forks(philo);
		return (false);
	}
	ft_usleep(philo, philo->program->time_to_eat);
	drop_forks(philo);
	return (true);
}

bool	p_sleep(t_philosopher *philo)
{
	if (!ft_log(philo, IS_SLEEPING, true))
		return (false);
	ft_usleep(philo, philo->program->time_to_sleep);
	return (true);
}
