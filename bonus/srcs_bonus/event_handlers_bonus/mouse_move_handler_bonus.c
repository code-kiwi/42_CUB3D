/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:15 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/28 10:07:58 by brappo           ###   ########.fr       */
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
		x_delta = abs(x - game->mlx.width_half);
		y_delta = abs(y - game->mlx.height_half);
		player->rotation_speed.x = (float)x_delta / MOTION_X_DECREASE_FACTOR;
		if (x > game->mlx.width_half)
			player->rotation_speed.x *= -1.0f;
		player->rotation_speed.y = (float)y_delta / MOTION_X_DECREASE_FACTOR;
		if (y > game->mlx.width_half)
			player->rotation_speed.y *= -1.0f;
	}
	return (1);
}
