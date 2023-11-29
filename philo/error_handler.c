/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:47:17 by arabelo-          #+#    #+#             */
/*   Updated: 2023/11/29 15:47:27 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// This function displays an error message explaining the wrong argument type.
void	no_num_param_error(void)
{
	write(2, NO_NUM_PARAM_ERROR_MESSAGE,
		ft_strlen(NO_NUM_PARAM_ERROR_MESSAGE));
}

// This function displays an error message
// explaining the wrong argument amount.
void	wrong_param_amount_error(void)
{
	write(2, WRONG_PARAM_AMOUNT_ERROR_MESSAGE1,
		ft_strlen(WRONG_PARAM_AMOUNT_ERROR_MESSAGE1));
	write(2, WRONG_PARAM_AMOUNT_ERROR_MESSAGE2,
		ft_strlen(WRONG_PARAM_AMOUNT_ERROR_MESSAGE2));
	write(2, WRONG_PARAM_AMOUNT_ERROR_MESSAGE3,
		ft_strlen(WRONG_PARAM_AMOUNT_ERROR_MESSAGE3));
	write(2, WRONG_PARAM_AMOUNT_ERROR_MESSAGE4,
		ft_strlen(WRONG_PARAM_AMOUNT_ERROR_MESSAGE4));
	write(2, WRONG_PARAM_AMOUNT_ERROR_MESSAGE5,
		ft_strlen(WRONG_PARAM_AMOUNT_ERROR_MESSAGE5));
}

// This function displays an error message
// explaining the signed argument.
void	signed_param_error(void)
{
	write(2, SIGNED_PARAM_ERROR_MESSAGE,
		ft_strlen(SIGNED_PARAM_ERROR_MESSAGE));
}
