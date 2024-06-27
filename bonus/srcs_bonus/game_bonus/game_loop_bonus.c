/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/27 10:21:31 by brappo           ###   ########.fr       */
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
	t_mlx_coords	start;
	t_mlx_coords	end;
	t_list			*path;

	delta_time = 0;
	if (game == NULL)
		error_exit(game, ERR_GAME_LOOP);
	game_loop_handle_fps(game, &delta_time);
	start = (t_mlx_coords){15, 11};
	end = (t_mlx_coords){18, 11};
	for (int i = 0;i < 10; i++)
	{
		path = find_path(&start, &end, &game->map);
		ft_lstclear(&path, free);
	}
	update_player(&game->player, &game->map, delta_time);
	update_doors(game, delta_time);
	if (!is_in_bounds(&game->player.position, &game->map))
		error_exit(game, ERR_PLAYER_QUIT_MAP);
	if (!cast_rays(game))
		error_exit(game, ERR_CAST_RAYS);
	draw_walls(game);
	render_all_sprites(game);
	if (!t_mlx_render(&game->mlx))
		error_exit(game, ERR_RENDER);
	printf("fps : %d\n", (int)(1.0f / delta_time));
	return (0);
}
