/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:39:34 by arabelo-          #+#    #+#             */
/*   Updated: 2023/11/29 17:24:28 by arabelo-         ###   ########.fr       */
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

// signed parameter error message
# define SIGNED_PARAM_ERROR_MESSAGE "Error: Signed parameter!\n"
// signed parameter error message
// MACROS

// error handler
void	no_num_param_error(void);
void	wrong_param_amount_error(void);
void	signed_param_error(void);
// error handler

// params_checker
bool	is_num(int c);
bool	is_param_valid(char *str);
bool	check_all_params(char **av);
// params_checker

// utils
size_t	ft_strlen(const char *str);
// utils

#endif
