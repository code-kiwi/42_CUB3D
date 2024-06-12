/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:45:49 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/12 17:53:13 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"

int	destroy_handler(t_cub_data *data)
{
	if (data == NULL)
		error_exit(NULL, ERROR_MSG_ARG);
	t_cub_data_destroy(data);
	exit(EXIT_SUCCESS);
	return (0);
}
