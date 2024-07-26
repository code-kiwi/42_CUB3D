/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:16:10 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/26 21:08:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "event_handlers.h"
#include "libft.h"

/**
 * @brief Handles the keyboard press key events
 * @param data The t_game which contains project data to affect
 * @param key The integer value of the pressed key
 * @return A dummy integer
*/
int	key_press_handler(int key, t_game *data)
{
	if (data == NULL)
		error_exit(NULL, ERR_ARG);
	if (key == KEY_RIGHT)
		data->player.turn_direction[1] = true;
	else if (key == KEY_LEFT)
		data->player.turn_direction[0] = true;
	else if (key == KEY_UP)
		data->player.turn_direction[2] = true;
	else if (key == KEY_DOWN)
		data->player.turn_direction[3] = true;
	else if (key == KEY_W)
		data->player.is_walking[FRONT] = true;
	else if (key == KEY_S)
		data->player.is_walking[BACK] = true;
	else if (key == KEY_A)
		data->player.is_walking[LEFT] = true;
	else if (key == KEY_D)
		data->player.is_walking[RIGHT] = true;
	return (0);
}
