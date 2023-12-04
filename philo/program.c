/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:13:00 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/04 15:31:25 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This function initializes the program, returns true if succeed,
// otherwise returns false.
/// @param ac 
/// @param av 
/// @param program 
/// @param monitor 
/// @return 
bool	init_program(int ac, char **av, t_program *program, t_monitor *monitor)
{
	program->ac = ac;
	program->av = av;
	program->monitor = monitor;
	program->philos_amount = ft_atoul(*av);
	program->created_forks_mutexes = 0;
	if (!init_monitor(program, av))
		return (false);
	if (!init_forks(program, program->philos_amount))
		return (false);
	if (!init_philos(program))
		return (false);
	return (true);
}

/// @brief This function executes for each thread the join function,
// in case of success it reutrns true, otherwise false.
/// @param program 
/// @return 
bool	run_program(t_program *program)
{
	size_t	i;

	i = 0;
	if (pthread_join(program->monitor->thread, NULL))
	{
		free_project(program, FP_LEVEL_5, &pthread_join_error);
		return (false);
	}
	while (i < program->philos_amount)
	{
		if (pthread_join(program->philos[i].thread, NULL))
		{
			free_project(program, FP_LEVEL_5, &pthread_join_error);
			return (false);
		}
		i++;
	}
	return (true);
}

/// @brief This function writes the given message in the terminal
// with the timestamp, and philosopher id.
/// @param philo 
/// @param str 
void	printf_msg(t_philo *philo, const char *str)
{
	pthread_mutex_lock(philo->printf_lock);
	if (!check_dead_flag(philo))
		printf("%li %li %s", timestamp() - philo->start_timestamp, philo->id, str);
	pthread_mutex_unlock(philo->printf_lock);
}

bool	check_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_flag_lock);
	if (*philo->anyone_dead)
	{
		pthread_mutex_unlock(philo->dead_flag_lock);
		return(true);
	}
	pthread_mutex_unlock(philo->dead_flag_lock);
	return (false);
}
