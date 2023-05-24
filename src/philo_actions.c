/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:46:53 by cbijman       #+#    #+#                 */
/*   Updated: 2023/05/24 17:37:30 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_eat(t_philosopher *philo)
{
	__THROW_NOT_IMPLEMENTED();
}

void	p_sleep(t_philosopher *philo)
{
	usleep(philo->program->time_to_sleep);
	printf("Ik slaap\n"); // <- aanpassen ofc.
}

void	p_think(t_philosopher *philo)
{
	__THROW_NOT_IMPLEMENTED();
}
