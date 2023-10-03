/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:27:29 by cbijman       #+#    #+#                 */
/*   Updated: 2023/10/03 15:27:24 by cbijman       ########   odam.nl         */
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
# include <sys/time.h>

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
	int				id;
	unsigned long	last_time_eat;
	pthread_t		thread_id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	t_program		*program;
}	t_philosopher;

typedef struct s_program
{
	pthread_mutex_t	*forks;
	time_t			time;
	unsigned int	number_of_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	times_to_eat;
}	t_program;

typedef void	(*t_philofunc)(t_philosopher *philo);

typedef struct s_philo_action
{
	t_philosopher			*philo;
	t_philofunc				*func;
	struct s_philo_action	*next;
}	t_philoaction;

//Libft funcs
void			*ft_calloc(int count, int size);
time_t			ft_gettime(void);
int				ft_isnumber(char const *str);

//Actions
void			p_eat(t_philosopher *philo);
void			p_sleep(t_philosopher *philo);
void			p_think(t_philosopher *philo);

// Functions
int				safe_atoi(const char *arg);
int				p_rand(int low_int, int max_int);
void			loop_time(void);
void			start_action(t_philosopher *philo, t_philofunc func);
void			philosleep(t_program *program, unsigned int time);
void			log_message_with_timestamp(t_philosopher *philo, const char *text);

#endif
