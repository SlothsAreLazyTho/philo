/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 12:40:30 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/02 12:35:29 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(unsigned int time)
{
	const time_t	start = ft_gettime();
	time_t			ms;

	ms = 0;
	while ((ft_gettime() - start) < time)
		usleep(150);
}

int	ft_isnumber(char const *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long long	n;
	int			i;
	int			multi;

	if (!str)
		return (0L);
	i = 0;
	n = 0;
	multi = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		multi *= -1;
		i += 1;
	}
	while (str[i] >= '0' || str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * multi);
}

void	*ft_calloc(int count, int size)
{
	void	*content;

	content = malloc(count * size);
	if (!content)
		return (NULL);
	memset(content, 0, size);
	return (content);
}
