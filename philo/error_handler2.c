/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:19:09 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/02 14:56:33 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This function displays an error message explaining
// that the memory allocation failed!
/// @param  
void	malloc_error(void)
{
	write(2, MALLOC_ERROR_MESSAGE, ft_strlen(MALLOC_ERROR_MESSAGE));
}

/// @brief This function displays an error message explaining
// that the mutex can not be destroyed.
/// @param  
void	mutex_destroy_error(void)
{
	write(2, MUTEX_DESTROY_ERROR_MESSAGE,
		ft_strlen(MUTEX_DESTROY_ERROR_MESSAGE));
}

/// @brief This function displays an error message explaining
// that the pthread_join function call failed.
/// @param  
void	pthread_join_error(void)
{
	write(2, PTHREAD_JOIN_ERROR_MESSAGE,
		ft_strlen(PTHREAD_JOIN_ERROR_MESSAGE));
}
