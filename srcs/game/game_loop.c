/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/14 12:32:38 by mhotting         ###   ########.fr       */
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
	static t_mlx_coords rect = {0, 0};

	if (game == NULL)
		error_exit(game, ERR_GAME_LOOP);
	game->mlx.event_loop_counter++;
	if (game->mlx.event_loop_counter >= EVENT_LOOP_FRAME_TARGET)
	{
		int	color = 0x00FF00;
		t_mlx_draw_line(game->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){WIN_WIDTH, 0}, color);
		t_mlx_draw_line(game->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){0, 0}, color);
		t_mlx_draw_line(game->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){0, WIN_HEIGHT}, color);
		t_mlx_draw_line(game->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){WIN_WIDTH, WIN_HEIGHT}, color);
		t_mlx_draw_line(game->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){WIN_WIDTH / 2, 0}, color);
		t_mlx_draw_line(game->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT}, color);
		t_mlx_draw_line(game->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){0, WIN_HEIGHT / 2}, color);
		t_mlx_draw_line(game->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){WIN_WIDTH, WIN_HEIGHT / 2}, color);
		t_mlx_draw_rectangle(game->mlx.img_buff, rect, (t_mlx_coords){50, 50}, color);
		if (!t_mlx_render(&game->mlx))
			error_exit(game, ERR_RENDER);
		rect.x++;
		rect.y++;
		game->mlx.event_loop_counter = 0;
	}
	return (0);
}
