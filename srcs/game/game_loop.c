/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/17 15:58:37 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "mlx_api.h"
#include "libft.h"

/**
 * @brief The main function called at each game loop iteration
 * @param game The project's game
 * @return A dummy integer
*/
int	game_loop(t_game *game)
{
	if (game == NULL)
		error_exit(game, ERR_GAME_LOOP);
	game->mlx.event_loop_counter++;
	if (game->mlx.event_loop_counter >= EVENT_LOOP_FRAME_TARGET)
	{
		update_player(&game->player, &game->map);
		if (!cast_rays(&game->player, &game->map, game->rays))
			error_exit(game, ERR_CAST_RAYS);
		draw_walls(game);
		if (!t_mlx_render(&game->mlx))
			error_exit(game, ERR_RENDER);
		if (!is_in_bounds(&game->player.position, &game->map))
			error_exit(game, ERR_PLAYER_QUIT_MAP);
		game->mlx.event_loop_counter = 0;
	}
	return (0);
}
