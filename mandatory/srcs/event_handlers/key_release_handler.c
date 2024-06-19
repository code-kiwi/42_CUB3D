/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:15:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/18 18:17:40 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "event_handlers.h"
#include "libft.h"

/**
 * @brief Handles the keyboard release key events
 * @param data The t_game which contains project data to affect
 * @param key The integer value of the pressed key
 * @return A dummy integer
*/
int	key_release_handler(int key, t_game *data)
{
	if (data == NULL)
		error_exit(NULL, ERR_ARG);
	if (key == KEY_RIGHT)
		data->player.turn_direction[1] = false;
	else if (key == KEY_LEFT)
		data->player.turn_direction[0] = false;
	else if (key == KEY_W)
		data->player.is_walking[FRONT] = false;
	else if (key == KEY_S)
		data->player.is_walking[BACK] = false;
	else if (key == KEY_A)
		data->player.is_walking[LEFT] = false;
	else if (key == KEY_D)
		data->player.is_walking[RIGHT] = false;
	else if (key == KEY_ESC)
		return (destroy_handler(data));
	return (0);
}
