/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:00:42 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/02 14:12:59 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief  This function initializes the monitor struct
/// @param program 
/// @param av 
/// @return 
bool	init_monitor(t_program *program, char **av)
{
	program->monitor->anyone_dead = false;
	if (pthread_mutex_init(&program->monitor->dead_flag_lock, NULL))
	{
		free_project(program, 0, &mutex_error);
		return (false);
	}
	if (pthread_mutex_init(&program->monitor->meals_flag_lock, NULL))
	{
		free_project(program, 1, &mutex_error);
		return (false);
	}
	if (pthread_mutex_init(&program->monitor->printf_lock, NULL))
	{
		free_project(program, 2, &mutex_error);
		return (false);
	}
	if (*(av + 4))
		program->monitor->num_least_meals = ft_atoul(*(av + 4));
	else
		program->monitor->num_least_meals = -1;
	return (true);
}
