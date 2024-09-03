/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:16:10 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/03 14:10:33 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "door_bonus.h"

/**
 * @brief Handles the keyboard press key events
 * @param game The t_game which contains project data to affect
 * @param key The integer value of the pressed key
 * @return A dummy integer
*/
int	key_press_handler(int key, t_game *game)
{
	if (game == NULL)
		error_exit(NULL, ERR_ARG);
	else if (game->state != STATE_PLAYING)
		return (0);
	else if (key == KEY_W)
		game->player.walk_direction[FRONT] = true;
	else if (key == KEY_S)
		game->player.walk_direction[BACK] = true;
	else if (key == KEY_A)
		game->player.walk_direction[LEFT] = true;
	else if (key == KEY_D)
		game->player.walk_direction[RIGHT] = true;
	else if (key == KEY_E)
		open_looked_door(game->player.look_ray, game->map);
	return (0);
}
