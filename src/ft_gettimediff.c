/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gettimediff.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 15:07:58 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/18 15:10:41 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_gettimediff(struct timeval start, struct timeval end)
{
	return (ft_getmilliseconds(start) - ft_getmilliseconds(end));
}

size_t	ft_gettimediffl(size_t start, size_t stop)
{
	return (start - stop);
}
