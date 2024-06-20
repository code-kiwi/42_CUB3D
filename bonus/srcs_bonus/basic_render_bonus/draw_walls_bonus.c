/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/06/20 09:57:25 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "cub3d_bonus.h"

static t_image	*get_texture(t_image textures[4], t_ray *ray)
{
	if (ray->is_vertical)
	{
		if (ray->slope.x > 0)
			return (&textures[3]);
		else
			return (&textures[1]);
	}
	else
	{
		if (ray->slope.y > 0)
			return (&textures[2]);
		else
			return (&textures[0]);
	}
}

static int	pixel_column_on_texture(t_ray *ray, int texture_width)
{
	int		column;
	float	texture_relative_position;
	double	temp;

	if (ray->is_vertical)
		texture_relative_position = modf(ray->intersection.y, &temp);
	else
		texture_relative_position = modf(ray->intersection.x, &temp);
	column = floorf(texture_relative_position * texture_width);
	return (column);
}

static void	draw_wall_column(size_t column_index, t_ray *ray, t_game *game)
{
	t_column	column;

	column.coords.x = column_index;
	column.perceived_height = WIN_HEIGHT
		/ (ray->length * cos(ray->angle_from_orientation));
	column.ray = ray;
	column.start = floorf((WIN_HEIGHT - column.perceived_height) / 2);
	column.end = ceilf((WIN_HEIGHT + column.perceived_height) / 2);
	if (column.end > WIN_HEIGHT)
		column.end = WIN_HEIGHT;
	column.coords.y = column.start;
	if (column.coords.y < 0)
		column.coords.y = 0;
	column.texture_start = column.coords.y - column.start;
	column.texture = get_texture(game->textures, ray);
	column.texture_column = pixel_column_on_texture(ray, column.texture->width);
	draw_texture_column(game->mlx.img_buff, &column,
		get_texture(game->textures, ray));
	draw_ground_ceiling(&column, WIN_HEIGHT, game, ray);
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
