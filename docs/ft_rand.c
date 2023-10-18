/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rand.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 16:30:44 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/18 17:16:14 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <math.h>

static int	ft_rand(int max_int)
{
	const int		a = 987654321;
	const int		b = 314159265;
	const int		c = 246813579;
	struct timeval	val;
	int				answer;

	gettimeofday(&val, NULL);
	val.tv_usec *= 0.5;
	answer = (a * ((val.tv_sec * 1000) + b) % c) % max_int;
	return (answer);
}
