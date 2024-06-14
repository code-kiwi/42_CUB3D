/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/14 16:20:13 by mhotting         ###   ########.fr       */
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
	static int	color = 0;
	if (game == NULL)
		error_exit(game, ERR_GAME_LOOP);
	game->mlx.event_loop_counter++;
	if (game->mlx.event_loop_counter >= EVENT_LOOP_FRAME_TARGET)
	{
		t_mlx_coords	point = {0, 0};
		t_mlx_coords	size = {WIN_WIDTH, WIN_HEIGHT};
		t_mlx_draw_rectangle(game->mlx.img_buff, point, size, color);
		ft_printf("LOOP %d\n", color);
		// cast_rays(&game->player, &game->map, game->rays);
		// draw_walls(game->mlx.img_buff, game->rays);
		if (!t_mlx_render(&game->mlx))
			error_exit(game, ERR_RENDER);
		game->mlx.event_loop_counter = 0;
		color++;
	}
	return (0);
}
