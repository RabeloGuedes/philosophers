/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:13:00 by arabelo-          #+#    #+#             */
/*   Updated: 2023/11/30 22:57:38 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
