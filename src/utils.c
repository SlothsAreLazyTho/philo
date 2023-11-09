/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 12:40:30 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/09 13:11:40 by cbijman       ########   odam.nl         */
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

bool	ft_isnumber(char const *str)
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	n;
	int		i;
	int		multi;

	if (!str)
		return (0L);
	i = 0;
	n = 0;
	multi = 1;
	while (str[i] <= 32 || str[i] >= 127)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			multi = -multi;
		i++;
	}
	while (str[i] && (str[i] >= '0' || str[i] <= '9'))
	{
		if (i > 10)
			return (-1);
		n = (n * 10) + (str[i++] - '0');
	}
	return (n * multi);
}

int32_t	ft_atoi(const char *str)
{
	int		i;
	int		multi;
	long	answer;

	i = 0;
	multi = 1;
	answer = 0;
	if (ft_strncmp(str, "-2147483648", 11) == 0)
		return (-2147483648);
	while (str[i] <= 32 || str[i] == 127)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			multi = -multi;
		i++;
	}
	while (str[i] && (str[i] >= '0' || str[i] <= '9'))
		answer = (answer * 10) + (str[i++] - '0');
	return (answer * multi);
}
