/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:30:18 by cbijman       #+#    #+#                 */
/*   Updated: 2023/05/22 20:01:50 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

enum	action
{
	SLEEP,
}

void	start_action(t_philo *philo, t_philofunc func)
{
	//pthread_mutex_lock();
	//func(philo);
	//pthread_mutex_unlock();
	//__THROW_NOT_IMPLEMENTED();
}

int	main(int argc, char *argv[])
{
	t_philo	philo;
	start_action(&philo, p_eat);
	return (0);
}
