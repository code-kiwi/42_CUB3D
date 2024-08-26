/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/26 16:07:14 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"
#include "libft.h"
#include "door_bonus.h"
#include "sprite_bonus.h"
#include "animation_bonus.h"
#include "entities_bonus.h"
#include "bullets_bonus.h"
#include "hud_bonus.h"

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

static void	game_render(t_game *game, float delta_time)
{
	t_mlx_center_cursor(&game->mlx);
	if (!game->mouse_hidden)
		t_mlx_mouse_hide(&game->mlx, &game->mouse_hidden);
	if (!update_entities(game, delta_time))
		error_exit(game, NULL);
	update_bullets(game, delta_time);
	if (!update_animations(game, delta_time))
		error_exit(game, NULL);
	update_player(game, delta_time);
	update_doors(game, delta_time);
	update_map(&game->map, game);
	if (!is_in_bounds(&game->player.position, &game->map))
		error_exit(game, ERR_PLAYER_QUIT_MAP);
	if (!cast_rays(game))
		error_exit(game, ERR_CAST_RAYS);
	draw_walls(game);
	render_all_sprites(game);
	draw_player(game, &game->player.weapon_info);
	draw_hud(game, &game->hud);
	if (game->map_opened)
		draw_map(&game->map.draw, &game->map, game);
	else
		draw_radar(game, &game->radar, &game->mlx);
}

static void	game_over_handler(t_game *game)
{
	if (!game->game_over)
	{
		game->game_over = true;
		draw_hud(game, &game->hud);
		t_mlx_mouse_show(&game->mlx, &game->mouse_hidden);
		t_mlx_sync_images(&game->mlx);
	}
	if (game->game_over_loop_count < GAMEOVER_DARKNESS_LOOP)
	{
		game->game_over_loop_count++;
		t_image_multiply_each_px(game->mlx.img_buff, GAMEOVER_DARKNESS);
	}
	draw_ui(&game->ui_game_over, game->mlx.img_buff);
}

int	game_loop(t_game *game)
{
	float	delta_time;

	delta_time = 0.1f;
	if (game == NULL)
		error_exit(game, ERR_GAME_LOOP);
	game_loop_handle_fps(game, &delta_time);
	if (game->player.is_dead)
		game_over_handler(game);
	else if (game->pause)
		draw_ui(&game->ui_pause, game->mlx.img_buff);
	else
		game_render(game, delta_time);
	if (!t_mlx_render(&game->mlx))
		error_exit(game, ERR_RENDER);
	// printf("fps : %d\n", (int)(1.0f / delta_time));
	return (0);
}
