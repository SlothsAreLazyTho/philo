/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:27:29 by cbijman       #+#    #+#                 */
/*   Updated: 2023/11/09 15:18:27 by cbijman       ########   odam.nl         */
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

# define IS_EATING "is eating"
# define IS_SLEEPING "is sleeping"
# define IS_THINKING "is thinking"
# define IS_DEAD "died"
# define TAKES_A_FORK "has taken a fork"

# define ERR_NO_FORK "Error while creating forks"
# define ERR_NO_PHILO "Error while creating philos"
# define ERR_NOT_ENOUGH_MEMORY "Not enough memory for allocation"
# define ERR_NOT_ENOUGH_ARGS "Not valid nor enough arguments provided"
# define ERR_W_THREADS "Error while creating threads"

# define MAX_THREADS 2047

typedef struct s_program	t_program;

typedef struct s_philosopher
{
	int32_t			id;
	pthread_mutex_t	lock;
	pthread_t		thread;
	time_t			last_time_eat;
	int32_t			times_eat;
	int32_t			left_fork;
	int32_t			right_fork;
	t_program		*program;
}	t_philosopher;

typedef struct s_program
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	bool			is_dead;
	time_t			time;
	int32_t			nb_of_philos;
	int32_t			time_to_die;
	int32_t			time_to_eat;
	int32_t			time_to_sleep;
	int32_t			times_eat;
}	t_program;

// Program functions
bool			is_valid_params(int ac, char **av);

// Initialization
bool			initialize_program(int ac, char **av, t_program *program);
bool			initialize_forks(t_program *program);
t_philosopher	**initialize_philosophers(t_program *program);
bool			initialize_threads(t_program *program,
					t_philosopher **philos, void *(*routine)(void *));

// Actions
bool			p_eat(t_philosopher *philo);
bool			p_sleep(t_philosopher *philo);

// Functions
bool			ft_log(t_philosopher *philo, const char *text, bool cd);

// Checkers
bool			did_everyone_eat(t_philosopher **philo);
bool			did_anyone_die(t_philosopher *philo);

// Cleanup
void			cleanup_program(t_program *program);
void			cleanup_philos(t_philosopher **philos);
void			cleanup_forks(t_program *program);
void			cleanup_threads(t_philosopher **philos);
void			cleanup(t_program *program, t_philosopher **philos);

// Utils
void			ft_usleep(unsigned int time);
long			ft_atol(const char *str);
int32_t			ft_atoi(const char *str);
bool			ft_isnumber(char const *str);
time_t			ft_gettime(void);
time_t			ft_getmilliseconds(struct timeval time);
time_t			ft_gettimediff(struct timeval start, struct timeval end);
time_t			ft_gettimediffl(time_t start, time_t stop);
time_t			ft_gettimewdiff(time_t diff);

#endif
