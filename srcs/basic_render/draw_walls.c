/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/06/16 15:39:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "math.h"
#include <stdio.h>

static bool	draw_wall_column(size_t column_index, t_ray *ray, t_image *screen,
	t_image textures[4])
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
	draw_color_column(screen, &column.coords, 0x00FF0000, wall_start);
	column.texture_start = column.coords.y - wall_start;
	draw_texture_column(screen, &column, wall_end, textures);
	draw_color_column(screen, &column.coords, 0x000000FF, WIN_HEIGHT);
	return (true);
}

bool	draw_walls(t_image *screen, t_ray *rays, t_image textures[4])
{
	size_t	index;

	index = 0;
	while (index < WIN_WIDTH)
	{
		if (!draw_wall_column(index, &rays[index], screen, textures))
			return (false);
		index++;
	}
	return (true);
}
