/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/09/03 14:47:27by brappo           ###   ########.fr       */
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

static float	range(float value)
{
	if (value < 0)
		return (0);
	if (value > WIN_HEIGHT)
		return (WIN_HEIGHT);
	return (value);
}

static void	draw_wall_column(size_t column_index, t_ray *ray, t_game *game)
{
	t_column	column;
	t_image		*texture;
	int			offset;
	int			player_height_offset;
	int			diff;
	int			saveEnd;
	int			player_height_diff;

	player_height_diff = game->player.camera_y_diff;
	offset = game->player.orientation.y;
	column.coords.x = column_index;
	column.perceived_height = WIN_HEIGHT
		/ (ray->length * ray->cos_angle_from_orientation);
	player_height_offset = player_height_diff - player_height_diff * column.perceived_height / WIN_HEIGHT;
	column.start = floorf((WIN_HEIGHT - column.perceived_height) / 2) + offset + player_height_offset;
	column.end = range((WIN_HEIGHT + column.perceived_height) / 2 + offset + player_height_offset);
	saveEnd = (WIN_HEIGHT + column.perceived_height) / 2 + offset + player_height_offset;
	column.coords.y = range(column.start);
	column.texture_start = column.coords.y - column.start;
	texture = get_texture(game->anim, ray);
	column.texture_column = pixel_column_on_texture(ray, texture->width);
	column.real_ceiling_start = WIN_HEIGHT - (WIN_HEIGHT - column.perceived_height) / 2;
	if (column.start >= WIN_HEIGHT)
		diff = column.start - WIN_HEIGHT;
	else
		diff = 0;
	draw_ceiling(&column, column.coords.y - 1, game, ray, diff);
	draw_texture_column(game->mlx.img_buff, &column, texture, ray->length);
	column.real_ground_start = (WIN_HEIGHT + column.perceived_height) / 2;
	if (saveEnd <= 0)
		diff = -saveEnd;
	else
		diff = 0;
	draw_ground(&column, column.coords.y, game, ray, diff);
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
