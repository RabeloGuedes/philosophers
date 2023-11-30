/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:19:09 by arabelo-          #+#    #+#             */
/*   Updated: 2023/11/30 16:51:22 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "philo.h"

// This function displays an error message explaining
// that the memory allocation failed!
void	malloc_error(void)
{
	write(2, MALLOC_ERROR_MESSAGE, ft_strlen(MALLOC_ERROR_MESSAGE));
}

// This function displays an error message explaining
// that the mutex can not be destroyed.
void	mutex_destroy_error(void)
{
	write(2, MUTEX_DESTROY_ERROR_MESSAGE,
		ft_strlen(MUTEX_DESTROY_ERROR_MESSAGE));
}