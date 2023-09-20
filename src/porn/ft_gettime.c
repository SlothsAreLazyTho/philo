/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gettime.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 10:29:01 by cbijman       #+#    #+#                 */
/*   Updated: 2023/09/20 10:29:18 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

time_t	ft_gettime(void)
{
	struct timeval	val;
	time_t			time;

	gettimeofday(&val, NULL);
	time = val.tv_usec / 1000;
	time += val.tv_sec * 1000;
	return (time);
}
