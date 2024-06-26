/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:16:10 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/26 07:25:23 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"
#include "libft.h"
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
	if (key == KEY_RIGHT)
		game->player.turn_direction[1] = true;
	else if (key == KEY_LEFT)
		game->player.turn_direction[0] = true;
	else if (key == KEY_W)
		game->player.is_walking[FRONT] = true;
	else if (key == KEY_S)
		game->player.is_walking[BACK] = true;
	else if (key == KEY_A)
		game->player.is_walking[LEFT] = true;
	else if (key == KEY_D)
		game->player.is_walking[RIGHT] = true;
	else if (key == KEY_P)
		game_pause_switch(game);
	else if (key == KEY_E)
		open_looked_door(game->player.look_ray, &game->map);
	return (0);
}
