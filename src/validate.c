/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/02 12:51:16 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/02 13:19:32 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stddef.h>
#include <limits.h>

static bool	is_valid_int32(long a)
{
	if (a < 0 || a > 2147483647)
		return (false);
	return (true);
}

bool	is_valid_params(int ac, char **av)
{
	long	tmp;
	int		index;
	
	if (ac < 5)
		return (false);
	index = 1;
	while (index < ac)
	{
		if (!ft_isnumber(av[index]))
			return (false);
		tmp = ft_atol(av[index]);
		if (!is_valid_int32(tmp))
			return (false);
		index++;
	}
	return (true);
}