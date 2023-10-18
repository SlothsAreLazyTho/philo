/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_usleep.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 13:34:18 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/18 15:09:15 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_usleep(unsigned int time)
{
	const time_t	start = ft_gettime();
	time_t			seconds;

	seconds = 0;
	while (seconds < time)
	{
		usleep(200);
		seconds = ft_gettime() - start;
	}
}
