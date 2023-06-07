/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_sleep.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 17:51:36 by cbijman       #+#    #+#                 */
/*   Updated: 2023/06/07 18:06:29 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosleep(t_program *program, uint32_t time)
{
	int seconds;
	
	seconds = 0;
	while (seconds < time)
	{
		usleep(1000);
		seconds++;
	}
}
 