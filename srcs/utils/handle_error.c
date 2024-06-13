/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:52:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:40:04 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/**
 * @brief Prints an error message on the appropriate file descriptor
 * @param err_msg The error message to print
 * @note If no message is provided, a standard message will be printed
*/
void	error_print(char *err_msg)
{
	if (err_msg != NULL)
		ft_dprintf(STDERR_FILENO, ERR_MSG_LITERALS, err_msg);
	else
		ft_dprintf(STDERR_FILENO, ERR_MSG_BASIC);
}

/**
 * @brief Destroys the given t_cub_data pointer, prints the err_msg and exits
 * @param data The project's data to destroy
 * @param err_msg The error message to display
*/
void	error_exit(t_cub_data *data, char *err_msg)
{
	if (data != NULL)
		t_cub_data_destroy(data);
	if (err_msg != NULL)
		error_print(err_msg);
	exit(EXIT_FAILURE);
}
