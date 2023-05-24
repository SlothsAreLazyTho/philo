/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:27:29 by cbijman       #+#    #+#                 */
/*   Updated: 2023/05/24 17:35:29 by cbijman       ########   odam.nl         */
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
    return ;							\
} while(0)

#define __THROW_NOT_IMPLEMENTED2() do {	\
   	printf("Not implemented!\n");		\
    return (NULL);						\
} while(0)

typedef struct s_program
{
	uint32_t	number_of_philosophers;
	uint32_t	time_to_die;
	uint32_t	time_to_eat;
	uint32_t	time_to_sleep;
	uint32_t	number_of_times_each_philosopher_must_eat;
}	t_program;

typedef struct s_philosopher
{
	int				id;
	t_program		*program;
	pthread_mutex_t	fork;
	pthread_t		thread_id;
}	t_philosopher;

typedef struct s_table
{
	t_philosopher	*philo;
	struct s_table	*next;
}	t_table;

typedef void	(*t_philofunc)(t_philosopher	*philo);


// Functions
void	*ft_calloc(int count, int type);
int		ps_isnumber(char const *str);
int		safe_atoi(const char *arg);
int		p_rand(int low_int, int max_int);


//Actions
void	p_eat(t_philosopher *philo);
void	p_sleep(t_philosopher *philo);
void	p_think(t_philosopher *philo);

//Table
t_table	*ps_newlst(t_philosopher *philo);
void	ps_lstadd_back(t_table **lst, t_table *nlst);
int		ps_lstsize(t_table **lst);

//Fun
void	loop_time(void);

#endif
