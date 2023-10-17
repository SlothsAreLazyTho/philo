/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gettimediff.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 15:07:58 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/17 15:11:02 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_gettimediff(struct timeval start, struct timeval end)
{
	return (ft_getmicroseconds(start) - ft_getmicroseconds(end));
}