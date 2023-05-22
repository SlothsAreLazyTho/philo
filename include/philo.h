/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:27:29 by cbijman       #+#    #+#                 */
/*   Updated: 2023/05/22 19:28:01 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

#define __THROW_NOT_IMPLEMENTED() do {	\
   	printf("Not implemented!\n");		\
    return;								\
} while(0)								\

typedef struct s_philo
{
	int	a;
}	t_philo;

typedef void	(*t_philofunc)(t_philo	*philo);


// Functions
void	*ft_calloc(int count, int type);
void	p_eat(t_philo *philo);
void	p_sleep(t_philo *philo);
void	p_think(t_philo *philo);

//Fun
void	loop_time(void);

#endif
