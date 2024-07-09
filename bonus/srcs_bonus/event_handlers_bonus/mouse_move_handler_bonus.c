/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:15 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/09 14:07:18 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"
#include "ui_bonus.h"



#include <stdio.h>

// static bool	mouse_cursor_needs_center(
// 	int win_w_center,
// 	int win_h_center,
// 	int x,
// 	int y
// )
// {
// 	return (
// 		x <= win_w_center - MOUSE_RESET_OFFSET
// 		|| x >= win_w_center + MOUSE_RESET_OFFSET
// 		|| y <= win_h_center - MOUSE_RESET_OFFSET
// 		|| y >= win_h_center + MOUSE_RESET_OFFSET
// 	);
// }

int	mouse_move_handler(int x, int y, t_game *game)
{
	if (game->pause)
		mouse_move_pause_handler(x, y, game);
	else
	{
		// printf("X_FINAL: %d\n", x);
		// printf("LAST_X_FINAL: %d\n", game->mlx.last_mouse_x_pos);
		if (x < game->mlx.last_mouse_x_pos)
			game->player.turn_direction[0] = true;
		else if (x > game->mlx.last_mouse_x_pos)
			game->player.turn_direction[1] = true;
		game->mlx.last_mouse_x_pos = x;
		t_mlx_center_cursor(&game->mlx);
		// printf("X_FINAL: %d\n", x);
		// printf("LAST_X_FINAL: %d\n", game->mlx.last_mouse_x_pos);
	}
	// printf("MOUSE X: %d\n", x);
	// printf("MOUSE Y: %d\n", y);
	return (1);
}
