/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_sleep.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 17:51:36 by cbijman       #+#    #+#                 */
/*   Updated: 2023/09/19 17:10:49 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosleeps(t_program *program, unsigned long time)
{
	int seconds;
	
	seconds = 0;
	while (seconds < time)
	{
		usleep(1000);
		seconds++;
	}
}
 