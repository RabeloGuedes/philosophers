/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:39:34 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/02 14:58:54 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// MACROS
// no numeric parameter error message
# define NO_NUM_PARAM_ERROR_MESSAGE "Error: Argument is not numeric!\n"
// no numeric parameter error message

// wrong parameter amount error messages
# define WRONG_PARAM_AMOUNT_ERROR_MESSAGE1 "Error: Wrong amount of arguments\n"
# define WRONG_PARAM_AMOUNT_ERROR_MESSAGE2 "usage: <number_of_philosophers> "
# define WRONG_PARAM_AMOUNT_ERROR_MESSAGE3 "<time_to_die_ms> <time_to_eat_ms>"
# define WRONG_PARAM_AMOUNT_ERROR_MESSAGE4 "<time_to_sleep_ms> [number_of_"
# define WRONG_PARAM_AMOUNT_ERROR_MESSAGE5 "times_each_philosopher_must_eat]\n"
// wrong parameter amount error messages

// mutex error message
# define MUTEX_ERROR_MESSAGE "Error: Mutex failed!\n"
# define MUTEX_DESTROY_ERROR_MESSAGE "Error: mutex can not be destroyed!\n"
// mutex error message

// malloc error message
# define MALLOC_ERROR_MESSAGE "Error: Malloc failed!\n"
// malloc error message

// pthread create error message
# define PTHREAD_CREATE_ERROR_MESSAGE "Error: Pthread creation failed!\n"
// pthread create error message

// pthread join error message
# define PTHREAD_JOIN_ERROR_MESSAGE "Error: Pthread join failed!\n"
// pthread join error message

// signed parameter error message
# define SIGNED_PARAM_ERROR_MESSAGE "Error: Signed parameter!\n"
// signed parameter error message

// Free project levels
# define FP_LEVEL_0 0
# define FP_LEVEL_1 1
# define FP_LEVEL_2 2
# define FP_LEVEL_3 3
# define FP_LEVEL_4 4
# define FP_LEVEL_5 5
// Free project levels

// MACROS

// STRUCTS
// philos
typedef struct s_philo
{
	bool			*anyone_dead;
	size_t			id;
	size_t			time_to_die_ms;
	size_t			time_to_eat_ms;
	size_t			time_to_sleep_ms;
	size_t			num_meals;
	size_t			philos_amount;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*dead_flag_lock;
	pthread_mutex_t	*printf_lock;
	pthread_mutex_t	*meals_flag_lock;
	pthread_t		thread;
}				t_philo;
// philos

// monitor
typedef struct s_monitor
{
	bool			anyone_dead;
	long			num_least_meals;
	pthread_mutex_t	dead_flag_lock;
	pthread_mutex_t	printf_lock;
	pthread_mutex_t	meals_flag_lock;
	t_philo			*philos;
}				t_monitor;
// monitor

// program
typedef struct s_program
{
	int				ac;
	char			**av;
	size_t			philos_amount;
	size_t			created_forks_mutexes;
	t_monitor		*monitor;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}		t_program;
// program
// STRUCTS

// error handler
void			no_num_param_error(void);
void			wrong_param_amount_error(void);
void			signed_param_error(void);
void			mutex_error(void);
void			pthread_create_error(void);
// error handler

// error handler 2
void			malloc_error(void);
void			mutex_destroy_error(void);
void			pthread_join_error(void);
// error handler 2

// forks
pthread_mutex_t	*create_forks(size_t num_of_philos);
bool			init_forks(t_program *program, size_t num_of_philos);
// forks

// memory
void			destroy_mutexes(pthread_mutex_t *forks, size_t num_of_philos);
void			free_project(t_program *program,
					size_t level, void (*call_back_fn)(void));
void			destroy_monitor(t_monitor *monitor, size_t level);
// memory

// monitor
bool			init_monitor(t_program *program, char **av);
// monitor

// params_checker
bool			is_num(int c);
bool			is_param_valid(char *str);
bool			check_all_params(char **av);
// params_checker

// philo routine
void			*philo_routine(void *phi);
// philo routine

// philos
bool			init_philos(t_program *program);
void			forks_on_table(t_program *program);
t_philo			*create_philos(size_t num_of_philos);
bool			init_threads(t_philo *philos, size_t philos_amount);
void			philos_attributes(char **av,
					t_philo *philos, t_monitor *monitor);
// philos

// program
bool			init_program(int ac, char **av,
					t_program *program, t_monitor *monitor);
bool			run_program(t_program *program);
// program

// utils
size_t			ft_strlen(const char *str);
size_t			ft_atoul(const char *str);
// utils
#endif
