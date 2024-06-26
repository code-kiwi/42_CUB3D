/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_handler_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:15:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/27 17:30:12 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"
#include "libft.h"

/**
 * @brief Handles the keyboard release key events
 * @param game The t_game which contains project data to affect
 * @param key The integer value of the pressed key
 * @return A dummy integer
*/
int	key_release_handler(int key, t_game *game)
{
	if (game == NULL)
		error_exit(NULL, ERR_ARG);
	if (key == KEY_RIGHT)
		game->player.turn_direction[1] = false;
	else if (key == KEY_LEFT)
		game->player.turn_direction[0] = false;
	else if (key == KEY_W)
		game->player.is_walking[FRONT] = false;
	else if (key == KEY_S)
		game->player.is_walking[BACK] = false;
	else if (key == KEY_A)
		game->player.is_walking[LEFT] = false;
	else if (key == KEY_D)
		game->player.is_walking[RIGHT] = false;
	else if (key == KEY_SPACE)
		player_shoot(game);
	else if (key == KEY_ESC)
		game_pause_switch(game);
	return (0);
}
