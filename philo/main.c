/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:41:56 by arabelo-          #+#    #+#             */
/*   Updated: 2023/11/30 22:59:14 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_program	program;
	t_monitor	monitor;

	if (ac == 5 || ac == 6)
	{
		if (!check_all_params(++av))
			return (1);
		if (!init_program(ac, av, &program, &monitor))
			return (1);
	}
	else
	{
		wrong_param_amount_error();
		return (1);
	}
	return (0);
}
