/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:45:44 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:07:00 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "event_handlers.h"
#include "libft.h"

/**
 * @brief Handles the keyboard pressed keys
 * @param data The t_cub_data which contains project data to affect
 * @param key The integer value of the pressed key
 * @return A dummy integer
*/
int	keyboard_handler(int key, t_cub_data *data)
{
	if (data == NULL)
		error_exit(NULL, ERROR_MSG_ARG);
	if (key == KEY_ESC)
		return (destroy_handler(data));
	else
		ft_printf("Key pressed: %d\n", key);
	return (0);
}
