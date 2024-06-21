/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:16:10 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/21 12:21:58 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"
#include "libft.h"

/**
 * @brief Handles the keyboard press key events
 * @param data The t_game which contains project data to affect
 * @param key The integer value of the pressed key
 * @return A dummy integer
*/

#include <stdio.h>
int	key_press_handler(int key, t_game *data)
{
	if (data == NULL)
		error_exit(NULL, ERR_ARG);
	if (key == KEY_RIGHT)
		data->player.turn_direction[1] = true;
	else if (key == KEY_LEFT)
		data->player.turn_direction[0] = true;
	else if (key == KEY_W)
		data->player.is_walking[FRONT] = true;
	else if (key == KEY_S)
		data->player.is_walking[BACK] = true;
	else if (key == KEY_A)
		data->player.is_walking[LEFT] = true;
	else if (key == KEY_D)
		data->player.is_walking[RIGHT] = true;
	else if (key == KEY_P)
	{
		data->pause = !data->pause;
		if (data->pause)
			t_mlx_sync_images(&data->mlx);
	}
		
	printf("KEY PRESSED: %d\n", key);
	return (0);
}
