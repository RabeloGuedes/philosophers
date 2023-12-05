/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atomic_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:29:32 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/05 20:02:57 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This function makes the philosopher grab two forks and
// eat displaying it in the terminal.
/// @param philo 
void	go_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		eat_even(philo);
	else
	{
		eat_odd(philo);
	}
	printf_msg(philo, EATING);
	philo->eating = true;
	pthread_mutex_lock(philo->timestamp_lock);
	philo->last_meal_timestamp = timestamp();
	pthread_mutex_unlock(philo->timestamp_lock);
	uwait(philo->time_to_eat_ms);
	pthread_mutex_lock(&philo->meals_flag_lock);
	philo->num_meals++;
	pthread_mutex_unlock(&philo->meals_flag_lock);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	philo->eating = false;
}

/// @brief This is the sequence for the philosophers, which the id is even,
// in this case the philosopher grabs the left fork first, then the right. 
void	eat_even(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf_msg(philo, TOOK_FORK);
	if (philo->philos_amount == 1)
	{
		uwait(philo->time_to_die_ms);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	printf_msg(philo, TOOK_FORK);
}

/// @brief This is the sequence for the philosophers, which the id is odd,
// in this case the philosopher grabs the right fork first, then the left. 
/// @param philo 
void	eat_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	printf_msg(philo, TOOK_FORK);
	if (philo->philos_amount == 1)
	{
		uwait(philo->time_to_die_ms);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	printf_msg(philo, TOOK_FORK);
}

/// @brief This function makes the philosopher sleep for the time_to_sleep_ms
// and displays it at the terminal.
/// @param philo 
void	go_sleep(t_philo *philo)
{
	printf_msg(philo, SLEEPING);
	uwait(philo->time_to_sleep_ms);
}

/// @brief This function makes the philosophers think
// and displays it in the terminal.
/// @param philo 
void	go_think(t_philo *philo)
{
	printf_msg(philo, THINKING);
	usleep(500);
}
