/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_calloc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 17:03:54 by cbijman       #+#    #+#                 */
/*   Updated: 2023/05/22 19:54:24 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(int count, int size)
{
	void	*content;

	content = malloc(count * size);
	if (!content)
		return (NULL);
	memset(content, 0, size);
	return (content);
}
