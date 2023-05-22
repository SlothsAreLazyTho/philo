/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 17:03:54 by cbijman       #+#    #+#                 */
/*   Updated: 2023/05/22 17:08:27 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(int count, int type)
{
	void	*content;

	content = malloc(count * type);
	if (!content)
		return (NULL);
	memset(content, 0, type);
	return (content);
}
