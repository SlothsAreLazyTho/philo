/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alloc.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 13:11:51 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/10 13:50:56 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stddef.h>
#include <stdarg.h>

void	ft_bzero(void *s, size_t n)
{
	memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

bool	ft_safe_mutex_init(int size, ...)
{
	va_list	mutexes;
	int		i;

	i = 0;
	va_start(mutexes, size);
	while (i < size)
	{
		if (pthread_mutex_init(va_arg(mutexes, pthread_mutex_t *), NULL) != 0)
		{
			va_end(mutexes);
			return (false);
		}
		i++;
	}
	va_end(mutexes);
	return (true);
}
