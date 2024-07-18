/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/17 10:58:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"
#include "libft.h"
#include "door_bonus.h"
#include "sprite_bonus.h"
#include "animation_bonus.h"
#include "entities_bonus.h"
#include "bullets_bonus.h"

static bool	game_loop_handle_fps(t_game *game, float *delta_time)
{
	long	time_to_wait;
	long	tick;

	tick = get_tick();
	if (tick == -1)
		return (false);
	if (game->tick_last_frame == 0)
	{
		game->tick_last_frame = tick;
		*delta_time = 0.1;
		return (true);
	}
	time_to_wait = game->tick_last_frame + game->frame_time_usec - tick;
	if (time_to_wait > 0 && time_to_wait < game->frame_time_usec)
	{
		if (usleep(time_to_wait) != 0)
			return (false);
		tick = get_tick();
		if (tick == -1)
			return (false);
	}
	*delta_time = (tick - game->tick_last_frame) / 1000000.0f;
	game->tick_last_frame = tick;
	return (true);
}

int	game_loop(t_game *game)
{
	float	delta_time;

	delta_time = 0.1f;
	if (game == NULL)
		error_exit(game, ERR_GAME_LOOP);
	game_loop_handle_fps(game, &delta_time);
	if (!game->pause)
	{
		t_mlx_center_cursor(&game->mlx);
		if (!game->mouse_hidden)
			t_mlx_mouse_hide(&game->mlx, &game->mouse_hidden);
		update_entities(game, delta_time);
		update_bullets(game, delta_time);
		update_animations(game, delta_time);
		update_player(&game->player, &game->map, delta_time, game->entities);
		update_doors(game, delta_time);
		if (!is_in_bounds(&game->player.position, &game->map))
			error_exit(game, ERR_PLAYER_QUIT_MAP);
		if (!cast_rays(game))
			error_exit(game, ERR_CAST_RAYS);
		draw_walls(game);
		render_all_sprites(game);
		draw_player(game);
	}
	else
		draw_ui(&game->ui_pause, game->mlx.img_buff);
	if (!t_mlx_render(&game->mlx))
		error_exit(game, ERR_RENDER);
	printf("fps : %d\n", (int)(1.0f / delta_time));
	return (0);
}
