/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_fun.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 19:26:58 by cbijman       #+#    #+#                 */
/*   Updated: 2023/05/24 15:59:07 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_time(struct timeval *val)
{
	static int	hours = 0;
	static int	minutes = 0;
	static int	second = 0;

	if (minutes >= 60)
	{
		hours += 1;
		minutes = 0;
	}
	if (second >= 60)
	{
		minutes++;
		second = 0;
	}

	second++;
	printf("\033[2J\033[HLog time: %02d:%02d:%02d\n",
		hours, minutes, second);
}

void	adjust_timer(int aseconds, int aminutes, int ahours, int first_run)
{
	static int	hours = 0;
	static int	minutes = 0;
	static int	second = 0;

	if (first_run)
	{
		hours = ahours;
		minutes = aminutes;
		second = aseconds;
	}
	if (hours > 0 && minutes == 0)
	{
		minutes = 60;
		hours--;
	}
	if (minutes > 0 && second == 0)
	{
		second = 60;
		minutes--;
	}
	if (hours == 0 && minutes == 0 && second == 0)
	{
		printf("\033[2J\033[HLogout from this computer (:\n");
		return ;
	}
	second--;
	printf("\033[2J\033[HTime remaining: %02d:%02d:%02d\n",
		hours, minutes, second);
}

void	loop_time(void)
{
	struct timeval			val;
	static struct timeval	new_time;

	gettimeofday(&val, NULL);
	adjust_timer(0, 0, 2, 1);
	while (1)
	{
		if (val.tv_sec != new_time.tv_sec)
		{
			adjust_timer(0, 0, 0, 0);
			//print_time(&val);
			new_time.tv_sec = val.tv_sec;
		}
		gettimeofday(&val, NULL);
	}
}
