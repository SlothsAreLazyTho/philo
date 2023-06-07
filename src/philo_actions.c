/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:46:53 by cbijman       #+#    #+#                 */
/*   Updated: 2023/06/07 18:05:22 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_eat(t_philosopher *philo)
{
	//philo->action = EATING;
	log_message_with_timestamp(philo, "is eating\n");
	philosleep(NULL, 500);
	p_think(philo);
}

void	p_sleep(t_philosopher *philo)
{
	//philo->action = SLEEPING;
	log_message_with_timestamp(philo, "is sleeping\n");
	philosleep(NULL, 500);
	p_eat(philo);
}

void	p_think(t_philosopher *philo)
{
	//philo->action = THINKING;
	log_message_with_timestamp(philo, "is thinking\n");
	philosleep(NULL, 500);
	//Time to think is geen ding. Dus laten we alle philosophers nadenken totdat alle forks weer op tafel liggen!
	p_sleep(philo);
}
