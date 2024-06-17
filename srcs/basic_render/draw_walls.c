/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/06/17 13:59:15 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

static void	draw_wall_column(size_t column_index, t_ray *ray, t_game *game)
{
	t_column	column;
	int			wall_start;
	int			wall_end;
	t_image		*screen;

	screen = game->mlx.img_buff;
	column.coords.y = 0;
	column.coords.x = column_index;
	column.perceived_height = WIN_HEIGHT
		/ (ray->length * cos(ray->angle_from_orientation));
	column.ray = ray;
	wall_start = floorf((WIN_HEIGHT - column.perceived_height) / 2);
	wall_end = floorf((WIN_HEIGHT + column.perceived_height) / 2);
	if (wall_end > WIN_HEIGHT)
		wall_end = WIN_HEIGHT;
	draw_color_column(screen, &column.coords, game->ground_color, wall_start);
	column.texture_start = column.coords.y - wall_start;
	if (ray->length == MAX_DISTANCE)
		draw_color_column(screen, &column.coords, 0, wall_end);
	else
		draw_texture_column(screen, &column, wall_end, game->textures);
	draw_color_column(screen, &column.coords, game->ceiling_color, WIN_HEIGHT);
}

void	draw_walls(t_game *game)
{
	size_t			index;

	index = 0;
	while (index < WIN_WIDTH)
	{
		draw_wall_column(index, &game->rays[index], game);
		index++;
	}
}
