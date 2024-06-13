/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:45:49 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:05:49 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"

/**
 * @brief Destroys the given t_cub_data instance and exits the program
 * @param data The t_cub_data instance to destroy before exiting
 * @return A dummy integer
*/
int	destroy_handler(t_cub_data *data)
{
	if (data == NULL)
		error_exit(NULL, ERROR_MSG_ARG);
	t_cub_data_destroy(data);
	exit(EXIT_SUCCESS);
	return (0);
}
