/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:15 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/10 12:17:16 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"
#include "ui_bonus.h"

int	mouse_move_handler(int x, int y, t_game *game)
{
	int	x_delta;

	if (game->pause)
		mouse_move_pause_handler(x, y, game);
	else
	{
		x_delta = abs(x - game->mlx.width_half);
		game->player.rotation_speed = (float)x_delta / MOTION_X_DECREASE_FACTOR;
		if (x > game->mlx.width_half)
			game->player.rotation_speed *= -1.0f;
	}
	return (1);
}
