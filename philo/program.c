/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:13:00 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/02 14:11:31 by arabelo-         ###   ########.fr       */
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
