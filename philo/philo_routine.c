/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:40:22 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/04 15:28:52 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This function makes the philosopher sleep for the time_to_sleep_ms
// and displays it at the terminal.
/// @param philo 
void	go_sleep(t_philo *philo)
{
	printf_msg(philo, SLEEPING);
	uwait(philo->time_to_die_ms * MICROSECONDS_IN_A_MILLISECOND);
}

/// @brief This function makes the philosophers think
// and displays it in the terminal.
/// @param philo 
void	go_think(t_philo *philo)
{
	printf_msg(philo, THINKING);
}

/// @brief This function makes the philosopher grab two forks and
// eat displaying it in the terminal.
/// @param philo 
void	go_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf_msg(philo, TOOK_FORK);
	if (philo->philos_amount == 1)
	{
		uwait(philo->time_to_die_ms * MICROSECONDS_IN_A_MILLISECOND);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	printf_msg(philo, TOOK_FORK);
	pthread_mutex_lock(philo->meals_flag_lock);
	printf_msg(philo, EATING);
	philo->eating = true;
	philo->num_meals++;
	uwait(philo->time_to_eat_ms * MICROSECONDS_IN_A_MILLISECOND);
	philo->last_meal_timestamp = timestamp();
	pthread_mutex_unlock(philo->meals_flag_lock);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	philo->eating = false;
}

/// @brief This function makes half of the philosophers sleep and
// the other half execute straitforward all routines.
/// @param phi 
/// @return 
void	*philo_routine(void *phi)
{
	t_philo	*philo;

	philo = (t_philo *)phi;
	if (philo->id % 2 == 0)
		go_sleep(philo);
	while (!check_dead_flag(philo))
	{
		go_eat(philo);
		go_sleep(philo);
		go_think(philo);
	}
	return (phi);
}
