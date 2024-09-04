/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/09/04 13:23:14 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "cub3d_bonus.h"
#include "libft.h"
#include "door_bonus.h"

static t_image	*get_texture(t_animation anim[MAP_NB_IDS], t_ray *ray)
{
	if (ray->is_door)
		return (anim[IDX_TXTR_DOOR].textures->content);
	if (ray->is_vertical)
	{
		if (ray->slope.x > 0)
			return (anim[IDX_TXTR_E].textures->content);
		else
			return (anim[IDX_TXTR_S].textures->content);
	}
	else
	{
		if (ray->slope.y > 0)
			return (anim[IDX_TXTR_W].textures->content);
		else
			return (anim[IDX_TXTR_N].textures->content);
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
	if (ray->is_door)
		texture_relative_position = ray->door->transition \
			- texture_relative_position;
	column = floorf(texture_relative_position * texture_width);
	return (column);
}

/*
ceiling start / ground start : 
	represents the ceiling start / wall start or ground start /wall  end, except
	they are not affected by the offsets.
	They are used to calculate the pixel position of the wall or ground.
start / end : 
	It's the position of the start/end but affected by the offsets.
ranged_start / ranged_end :
	Those are the real position the drawing start or end by, they'r between 
	[0,WIN_HEIGHT].
*/

/// @brief Draw a column of the screen
/// @param column_index The index of the column to draw [0,WIn_HEIGHT]
/// @param ray The ray which come from the player to the wall
/// @param game The game structure
static void	draw_wall_column(size_t column_index, t_ray *ray, t_game *game)
{
	t_column	column;
	t_image		*texture;
	int			offset;

	column.coords.x = column_index;
	column.perceived_height = WIN_HEIGHT / (ray->length * ray->cos_angle);
	offset = get_offset(column.perceived_height, &game->player);
	column.ceiling_start = (WIN_HEIGHT - column.perceived_height) / 2;
	column.start = column.ceiling_start + offset;
	column.ceiling_start = WIN_HEIGHT - column.ceiling_start;
	column.ground_start = (WIN_HEIGHT + column.perceived_height) / 2;
	column.end = column.ground_start + offset;
	column.ranged_end = range(column.end, 0, WIN_HEIGHT);
	column.ranged_start = range(column.start, 0, WIN_HEIGHT);
	column.coords.y = column.ranged_start;
	column.texture_start = column.coords.y - column.start;
	texture = get_texture(game->anim, ray);
	column.texture_x = pixel_column_on_texture(ray, texture->width);
	draw_ceiling(&column, column.coords.y - 1, game, ray);
	draw_texture_column(game->mlx.img_buff, &column, texture, ray->length);
	draw_ground(&column, column.coords.y, game, ray);
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
