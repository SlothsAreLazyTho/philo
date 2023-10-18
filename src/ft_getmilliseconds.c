/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getmilliseconds.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 15:09:40 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/18 15:10:36 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_getmilliseconds(struct timeval time)
{
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}
