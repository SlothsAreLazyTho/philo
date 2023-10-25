/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_usleep.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 13:34:18 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/25 15:48:57 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_usleep(unsigned int time)
{
	const time_t	start = ft_gettime();
	time_t			ms;

	ms = 0;
	while ((ft_gettime() - start) < time)
		usleep(150);
}
