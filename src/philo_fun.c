/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_fun.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 19:26:58 by cbijman       #+#    #+#                 */
/*   Updated: 2023/05/22 19:44:21 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "ft_printf.h"

void	print_time(struct timeval *val)
{
	static int	hours = 0;
	static int	minutes = 0;
	static int	second = 0;

	if (minutes > 60)
	{
		hours += 1;
		minutes = 0;
	}
	if (second > 60)
	{
		minutes++;
		second = 0;
	}

	second++;
	printf("\033[2J\033[HYour current time bud: %02d:%02d:%02d\n", hours, minutes, second);
}

void	loop_time(void)
{
	struct timeval val;
	static struct timeval new_time;
	while (1)
	{
		if (val.tv_sec != new_time.tv_sec)
		{
			print_time(&val);
			new_time.tv_sec = val.tv_sec;
		}
		gettimeofday(&val, NULL);
	}
}