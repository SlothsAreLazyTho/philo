/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 10:29:01 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/23 12:14:14 by cbijman       ########   odam.nl         */
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

time_t	ft_gettimediff(struct timeval start, struct timeval end)
{
	return (ft_getmilliseconds(start) - ft_getmilliseconds(end));
}

time_t	ft_gettimediffl(time_t start, time_t stop)
{
	return (start - stop);
}

time_t	ft_gettimewdiff(time_t diff)
{
	return (ft_gettimediffl(ft_gettime(), diff));
}

time_t	ft_getmilliseconds(struct timeval time)
{
	if (!time.tv_sec || !time.tv_usec)
		return (0);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}
