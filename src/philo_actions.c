/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:46:53 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/05 15:16:30 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->program->forks[philo->right_fork]);
	pthread_mutex_lock(&philo->program->forks[philo->left_fork]);
	log_message_with_timestamp(philo, "is eating\n");
	philosleep(NULL, 500);
	pthread_mutex_unlock(&philo->program->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->program->forks[philo->left_fork]);
	p_sleep(philo);
}

void	p_sleep(t_philosopher *philo)
{
	log_message_with_timestamp(philo, "is sleeping\n");
	philosleep(NULL, 500);
	p_think(philo);
}

void	p_think(t_philosopher *philo)
{
	log_message_with_timestamp(philo, "is thinking\n");
	philosleep(NULL, 500);
	p_eat(philo);
}
