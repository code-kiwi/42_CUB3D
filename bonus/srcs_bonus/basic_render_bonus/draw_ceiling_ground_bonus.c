/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_ground_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:24:21 by brappo            #+#    #+#             */
/*   Updated: 2024/09/04 13:32:03 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "mlx_api_bonus.h"
#include "cub3d_bonus.h"
#include "libft.h"

static	void	get_pixel_position_in_tile(t_ray *ray,
	t_vector *player_position, t_vector *result, float inv_dist)
{
	result->x = player_position->x + ray->slope.x / inv_dist;
	result->y = player_position->y - ray->slope.y / inv_dist;
	result->x -= (int)result->x;
	result->y -= (int)result->y;
}

static void	draw_pixel_from_texture(t_vector *pos_in_tile, char *addr,
	t_image *texture, float inv_dist)
{
	t_mlx_coords	color_coords;
	unsigned int	color;

	color_coords.x = pos_in_tile->x * texture->width;
	color_coords.y = pos_in_tile->y * texture->height;
	color = *(unsigned int *)(texture->addr + \
		color_coords.y * texture->line_len \
		+ (color_coords.x * texture->bpp_factor));
	multiply_color(&color, 1 - 1 / (inv_dist * MAX_VISION_DISTANCE));
	*(unsigned int *)addr = color;
}

static float	get_inv_dist(int start, float cos_angle)
{
	float	inv_dist;

	inv_dist = start * cos_angle / (WIN_HEIGHT / 2) - cos_angle;
	return (inv_dist);
}

/*
	To draw the ground we need the world position of the pixel, for that, we
	need to know his distance from the player.
	I calculate the inverse distance because it allows me to just add a variable
	each loop instead of recalculating the whole thing.
	inv_dist = inverse distance
	inv_dist_unit = inverse_distance_unit
	When the ground start is out of the screen, we need to add those out of the
	screen pixel to the distance, otherwise the ground would move with the
	screen border.
*/
/// @brief Draw the ground texture from start to WIN_HEIGHT
/// @param column The column data to draw
/// @param start The pixel y start
void	draw_ground(t_column *column, int start, t_game *game, t_ray *ray)
{
	float		inv_dist;
	float		inv_dist_unit;
	t_vector	pixel_position;
	char		*addr;
	int			height_diff;

	height_diff = game->player.camera_y_diff;
	inv_dist = get_inv_dist(column->ground_start, ray->cos_angle);
	inv_dist_unit = ray->cos_angle / (WIN_HEIGHT / 2 - height_diff);
	inv_dist += max_int(-column->end, 0) * inv_dist_unit;
	addr = t_mlx_get_pixel(game->mlx.img_buff, column->coords.x, start);
	while (start < WIN_HEIGHT)
	{
		get_pixel_position_in_tile(ray, &game->player.position,
			&pixel_position, inv_dist);
		draw_pixel_from_texture(&pixel_position, addr,
			game->anim[IDX_TXTR_FLOOR].textures->content, inv_dist);
		start++;
		inv_dist += inv_dist_unit;
		addr += game->mlx.img_buff->line_len;
	}
}

/*
Look at the commentary of draw_ground
*/
/// @brief Draw the ground texture from 0 to start
/// @param column The column data to draw
/// @param start The pixel y start
void	draw_ceiling(t_column *column, int start, t_game *game, t_ray *ray)
{
	float		inv_dist;
	float		inv_dist_unit;
	t_vector	pixel_position;
	char		*addr;
	int			height_diff;

	height_diff = game->player.camera_y_diff;
	inv_dist = get_inv_dist(column->ceiling_start, ray->cos_angle);
	inv_dist_unit = ray->cos_angle / (WIN_HEIGHT / 2 + height_diff);
	inv_dist += max_int(column->start - WIN_HEIGHT, 0) * inv_dist_unit;
	addr = t_mlx_get_pixel(game->mlx.img_buff, column->coords.x, start);
	while (start >= 0)
	{
		get_pixel_position_in_tile(ray, &game->player.position,
			&pixel_position, inv_dist);
		draw_pixel_from_texture(&pixel_position, addr,
			game->anim[IDX_TXTR_CEIL].textures->content, inv_dist);
		start--;
		inv_dist += inv_dist_unit;
		addr -= game->mlx.img_buff->line_len;
	}
}
