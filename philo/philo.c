/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:14:56 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/02 14:42:24 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This function creates an array of philosophers.
/// @param num_of_philos 
/// @return 
t_philo	*create_philos(size_t num_of_philos)
{
	t_philo	*philos;

	philos = (t_philo *)malloc(sizeof(t_philo) * num_of_philos);
	if (!philos)
		return (NULL);
	return (philos);
}

/// @brief This function initializes the threads, if it succeed returns true,
/// otherwise returns false.
/// @param philos 
/// @param forks 
/// @param philos_amount 
/// @return 
bool	init_threads(t_philo *philos, size_t philos_amount)
{
	size_t	i;

	i = 0;
	while (i < philos_amount)
	{
		if (pthread_create(&philos[i].thread, NULL, &philo_routine, &philos[i]))
			return (false);
		i++;
	}
	return (true);
}

/// @brief This function assigns to each philosophers its attributes.
/// @param ac 
/// @param av 
/// @param philos 
/// @param monitor 
void	philos_attributes(char **av,
	t_philo *philos, t_monitor *monitor)
{
	size_t	philos_amount;
	size_t	i;

	philos_amount = ft_atoul(*av);
	i = 0;
	while (i < philos_amount)
	{
		philos[i].id = i + 1;
		philos[i].philos_amount = philos_amount;
		philos[i].anyone_dead = &monitor->anyone_dead;
		philos[i].dead_flag_lock = &monitor->dead_flag_lock;
		philos[i].meals_flag_lock = &monitor->meals_flag_lock;
		philos[i].printf_lock = &monitor->printf_lock;
		philos[i].time_to_die_ms = ft_atoul(*(av + 1));
		philos[i].time_to_eat_ms = ft_atoul(*(av + 2));
		philos[i].time_to_sleep_ms = ft_atoul(*(av + 3));
		philos[i].num_meals = 0;
		i++;
	}
}

/// @brief This function assigns to each philosophers a left and a right forks.
/// @param program 
void	forks_on_table(t_program *program)
{
	size_t	i;

	i = 0;
	while (i < program->philos_amount)
	{
		program->philos[i].left_fork = &program->forks[i];
		if (i == 0)
			program->philos[i].right_fork = \
				&program->forks[program->philos_amount - 1];
		else
			program->philos[i].right_fork = &program->forks[i - 1];
		i++;
	}
}

/// @brief This function initilazes the philos, if it fails deallocates
// all previously allocated memory and returns false, otherwise true.
/// @param program
/// @return 
bool	init_philos(t_program *program)
{
	program->philos = create_philos(program->philos_amount);
	if (!program->philos)
	{
		free_project(program, FP_LEVEL_4, &malloc_error);
		return (false);
	}
	program->monitor->philos = program->philos;
	if (!init_threads(program->philos, program->philos_amount))
	{
		free_project(program, FP_LEVEL_5, &pthread_create_error);
		return (false);
	}
	philos_attributes(program->av,
		program->philos, program->monitor);
	forks_on_table(program);
	return (true);
}
