/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/19 16:29:45 by cbijman       #+#    #+#                 */
/*   Updated: 2023/09/19 16:30:27 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*ft_calloc(int count, int size)
{
	void	*content;

	content = malloc(count * size);
	if (!content)
		return (NULL);
	memset(content, 0, size);
	return (content);
}