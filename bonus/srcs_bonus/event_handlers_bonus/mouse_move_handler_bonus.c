/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:15 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/28 10:26:55 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"
#include "ui_bonus.h"

int	mouse_move_handler(int x, int y, t_game *game)
{
	int			x_delta;
	int			y_delta;
	t_player	*player;

	if (game->pause)
		mouse_move_pause_handler(x, y, game);
	else
	{
		player = &game->player;
		x_delta = game->mlx.width_half - x;
		y_delta = game->mlx.height_half - y;
		player->rotation_speed.x = (float)x_delta / MOTION_X_DECREASE_FACTOR;
		player->rotation_speed.y = (float)y_delta / MOTION_X_DECREASE_FACTOR;
	}
	return (1);
}
