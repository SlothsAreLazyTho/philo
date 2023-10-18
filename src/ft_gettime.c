/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gettime.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 10:29:01 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/18 14:42:11 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

time_t	ft_gettime(void)
{
	struct timeval	val;
	time_t			time;

	gettimeofday(&val, NULL);
	time = ft_getmilliseconds(val);
	return (time);
}
