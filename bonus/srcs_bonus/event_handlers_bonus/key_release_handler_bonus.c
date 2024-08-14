/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_handler_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:15:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/26 22:03:31 by codekiwi         ###   ########.fr       */
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
	if (key == KEY_W)
		game->player.walk_direction[FRONT] = false;
	else if (key == KEY_S)
		game->player.walk_direction[BACK] = false;
	else if (key == KEY_A)
		game->player.walk_direction[LEFT] = false;
	else if (key == KEY_D)
		game->player.walk_direction[RIGHT] = false;
	else if (!game->pause && key == KEY_M)
		game->map_opened = !game->map_opened;
	else if (key == KEY_ESC)
		game_pause_switch(game);
	return (0);
}
