/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:15 by codekiwi          #+#    #+#             */
/*   Updated: 2024/09/05 08:40:24 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"

int	mouse_move_handler(int x, int y, t_game *game)
{
	int			x_delta;
	int			y_delta;
	t_player	*player;

	if (game->state == STATE_GAMEOVER)
		mouse_move_gameover_handler(x, y, game);
	else if (game->state == STATE_GAMEWIN)
		mouse_move_gamewon_handler(x, y, game);
	else if (game->state == STATE_PAUSE)
		mouse_move_pause_handler(x, y, game);
	else if (game->state == STATE_HOME)
		mouse_move_home_handler(x, y, game);
	else if (game->state == STATE_LEVEL_SELECTION)
		mouse_move_level_selection_handler(x, y, game);
	else
	{
		player = &game->player;
		x_delta = game->mlx.width_half - x;
		y_delta = game->mlx.height_half - y;
		player->rotation_speed.x = (float)x_delta * MOTION_X_FACTOR;
		player->rotation_speed.y = (float)y_delta * MOTION_Y_FACTOR;
	}
	return (1);
}
