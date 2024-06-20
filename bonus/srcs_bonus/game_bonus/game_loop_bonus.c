/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/20 12:48:02 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"
#include "libft.h"

static bool	game_loop_handle_fps(t_game *game, float *delta_time)
{
	long	time_to_wait;
	long	tick;

	tick = get_tick();
	if (tick == -1)
		return (false);
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

	if (game == NULL)
		error_exit(game, ERR_GAME_LOOP);
	game_loop_handle_fps(game, &delta_time);
	update_player(&game->player, &game->map, delta_time);
	if (!is_in_bounds(&game->player.position, &game->map))
		error_exit(game, ERR_PLAYER_QUIT_MAP);
	if (!cast_rays(&game->player, &game->map, game->rays))
		error_exit(game, ERR_CAST_RAYS);
	draw_walls(game);
	draw_sprite(&game->sprite, game);
	if (!t_mlx_render(&game->mlx))
		error_exit(game, ERR_RENDER);
	return (0);
}
