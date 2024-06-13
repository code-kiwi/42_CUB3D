/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:08:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "mlx_api.h"
#include "libft.h"

/**
 * @brief The main function called at each game loop iteration
 * @param data The project's data
 * @return A dummy integer
*/
int	game_loop(t_cub_data *data)
{
	static t_mlx_coords rect = {0, 0};

	if (data == NULL)
		error_exit(data, ERR_MSG_GAME_LOOP);
	data->mlx.event_loop_counter++;
	if (data->mlx.event_loop_counter >= EVENT_LOOP_FRAME_TARGET)
	{
		int	color = 0x00FF00;
		t_mlx_draw_line(data->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){WIN_WIDTH, 0}, color);
		t_mlx_draw_line(data->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){0, 0}, color);
		t_mlx_draw_line(data->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){0, WIN_HEIGHT}, color);
		t_mlx_draw_line(data->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){WIN_WIDTH, WIN_HEIGHT}, color);
		t_mlx_draw_line(data->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){WIN_WIDTH / 2, 0}, color);
		t_mlx_draw_line(data->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT}, color);
		t_mlx_draw_line(data->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){0, WIN_HEIGHT / 2}, color);
		t_mlx_draw_line(data->mlx.img_buff, (t_mlx_coords){WIN_WIDTH / 2, WIN_HEIGHT / 2}, (t_mlx_coords){WIN_WIDTH, WIN_HEIGHT / 2}, color);
		t_mlx_draw_rectangle(data->mlx.img_buff, rect, (t_mlx_coords){50, 50}, color);
		if (!t_mlx_render(&data->mlx))
			error_exit(data, ERR_MSG_RENDER);
		rect.x++;
		rect.y++;
		data->mlx.event_loop_counter = 0;
	}
	return (0);
}
