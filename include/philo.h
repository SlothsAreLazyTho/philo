/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:27:29 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/17 13:45:24 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <stddef.h>
# include <sys/time.h>
# include <sys/types.h>

typedef	int t_fork_id;

typedef enum e_philo_action
{
	SLEEPING,
	EATING,
	THINKING,
	DEAD,
}	t_action;

typedef struct s_program	t_program;

typedef struct s_philosopher
{
	u_int32_t		id;
	pthread_t		thread_id;
	u_int64_t		last_time_eat;
	t_fork_id		left_fork;
	t_fork_id		right_fork;
	pthread_mutex_t	eat_lock;
	bool			can_eat;
	t_program		*program;
}	t_philosopher;

typedef struct s_program
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	can_write;
	pthread_mutex_t	can_eat;
	time_t			time;
	u_int32_t		nb_of_philos;
	u_int32_t		time_to_die;
	u_int32_t		time_to_eat;
	u_int32_t		time_to_sleep;
	u_int32_t		times_eat;
}	t_program;

typedef void	(*t_philofunc)(t_philosopher *philo);

//Libft funcs
void			*ft_calloc(int count, int size);
time_t			ft_gettime(void);
int				ft_isnumber(char const *str);
void			ft_usleep(unsigned int time);

//Actions
bool			p_eat(t_philosopher *philo);
bool			p_sleep(t_philosopher *philo);
bool			p_think(t_philosopher *philo);

// Functions
int				safe_atoi(const char *arg);
int				p_rand(int low_int, int max_int);
void			loop_time(void);
void			start_action(t_philosopher *philo, t_philofunc func);
void			log_message_with_timestamp(t_philosopher *philo, const char *text);

#endif
