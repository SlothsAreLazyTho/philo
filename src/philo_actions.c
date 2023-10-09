/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:46:53 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/09 15:33:13 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_eat(t_philosopher *philo)
{
	//pthread_mutex_lock(&philo->eat_lock);

	pthread_mutex_lock(&philo->program->forks[philo->right_fork]);
	pthread_mutex_lock(&philo->program->forks[philo->left_fork]);
	log_message_with_timestamp(philo, "has taken a fork\n");
	log_message_with_timestamp(philo, "has taken a fork\n");
	log_message_with_timestamp(philo, "is eating\n");
	philosleep(NULL, philo->program->time_to_eat);
	pthread_mutex_unlock(&philo->program->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->program->forks[philo->left_fork]);
	//pthread_mutex_unlock(&philo->eat_lock);
	p_sleep(philo);
}



void	p_sleep(t_philosopher *philo)
{
	log_message_with_timestamp(philo, "is sleeping\n");
	philosleep(NULL, philo->program->time_to_sleep);
	p_think(philo);
}

void	p_think(t_philosopher *philo)
{
	log_message_with_timestamp(philo, "is thinking\n");
	//philosleep(NULL, /);
	p_eat(philo);
}
