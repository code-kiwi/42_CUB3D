/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_handler_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:11 by codekiwi          #+#    #+#             */
/*   Updated: 2024/09/03 14:42:44 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"

int	mouse_release_handler(int button, int x, int y, t_game *game)
{
	if (button == MOUSE_LEFT && game->state == STATE_PAUSE)
		mouse_release_pause_handler(x, y, game);
	else if (button == MOUSE_LEFT && game->state == STATE_GAMEOVER)
		mouse_release_gameover_handler(x, y, game);
	else if (button == MOUSE_LEFT && game->state == STATE_GAMEWIN)
		mouse_release_gamewon_handler(x, y, game);
	else if (button == MOUSE_LEFT && game->state == STATE_HOME)
		mouse_release_home_handler(x, y, game);
	else if (button == MOUSE_LEFT && game->state == STATE_LEVEL_SELECTION)
		mouse_release_level_selection_handler(x, y, game);
	else if (button == MOUSE_LEFT)
		player_weapon_use_stop(&game->player.weapon_info, game);
	return (1);
}
