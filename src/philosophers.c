/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:02:05 by cbijman       #+#    #+#                 */
/*   Updated: 2023/05/31 18:04:20 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher	*recruit_philosopher(t_program *program)
{
	t_philosopher	*person;
	static int		size = 1;

	person = ft_calloc(1, sizeof(t_philofunc));
	person->id = size++;
	return (person);
}