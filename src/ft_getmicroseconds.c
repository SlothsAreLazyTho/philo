/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getmicroseconds.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 15:09:40 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/17 15:10:21 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_getmicroseconds(struct timeval time)
{
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}