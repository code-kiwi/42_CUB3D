/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/06/16 18:06:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "math.h"
#include <stdio.h>

static bool	draw_wall_column(size_t column_index, t_ray *ray, t_game *game)
{
	t_column	column;
	int			wall_start;
	int			wall_end;

	column.perceived_height = WIN_HEIGHT
		/ (ray->length * cos(ray->angle_from_orientation));
	column.coords.y = 0;
	column.coords.x = column_index;
	column.ray = ray;
	wall_start = floorf((WIN_HEIGHT - column.perceived_height) / 2);
	wall_end = floorf((WIN_HEIGHT + column.perceived_height) / 2);
	if (wall_end > WIN_HEIGHT)
		wall_end = WIN_HEIGHT;
	draw_color_column(game->mlx.img_buff, &column.coords,
		game->ground_color, wall_start);
	column.texture_start = column.coords.y - wall_start;
	draw_texture_column(game->mlx.img_buff, &column, wall_end, game->textures);
	draw_color_column(game->mlx.img_buff, &column.coords,
		game->ceiling_color, WIN_HEIGHT);
	return (true);
}

bool	draw_walls(t_game *game)
{
	size_t	index;

	index = 0;
	while (index < WIN_WIDTH)
	{
		if (!draw_wall_column(index, &game->rays[index], game))
			return (false);
		index++;
	}
	return (true);
}
