/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_rand.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 16:30:44 by cbijman       #+#    #+#                 */
/*   Updated: 2023/09/19 16:33:25 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <math.h>

static int	lcg_rand(int max_int)
{
	const int		a = 987654321;
	const int		b = 314159265;
	const int		c = 246813579;
	struct timeval	val;
	static int	answer = 0;

	gettimeofday(&val, NULL);
	val.tv_usec *= 0.5;
	answer = (a * ((val.tv_sec * 1000) + b) % c) % max_int;
	return (answer);
}

int	p_odd_or_even(void)
{
	static int times = 0;

	times++;
	return (times % 2);
}

int p_rand(int low_int, int max_int)
{
    static int old_i = -1;
    int new_i;

    do {
        new_i = lcg_rand(max_int);
    } while (new_i < low_int || old_i == new_i);

    old_i = new_i;
    return new_i;
}

