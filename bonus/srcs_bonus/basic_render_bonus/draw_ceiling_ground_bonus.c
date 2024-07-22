/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_ground_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:24:21 by brappo            #+#    #+#             */
/*   Updated: 2024/07/22 22:29:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "mlx_api_bonus.h"
#include "cub3d_bonus.h"
#include "libft.h"

static	void	get_pixel_position_in_tile(t_ray *ray,
	t_vector *player_position, t_vector *result, float inverse_dist)
{
	result->x = player_position->x + ray->slope.x / inverse_dist;
	result->y = player_position->y - ray->slope.y / inverse_dist;
	result->x -= (int)result->x;
	result->y -= (int)result->y;
}

static void	draw_pixel_from_texture(t_vector *pos_in_tile, char *addr,
	t_image *texture, float distance)
{
	t_mlx_coords	color_coords;
	unsigned int	color;

	color_coords.x = pos_in_tile->x * texture->width;
	color_coords.y = pos_in_tile->y * texture->height;
	color = *(unsigned int *)(texture->addr + \
		color_coords.y * texture->line_len \
		+ (color_coords.x * texture->bpp_factor));
	multiply_color(&color, 1 - distance / MAX_VISION_DISTANCE);
	*(unsigned int *)addr = color;
}

void	draw_ground_ceiling(t_column *column, int end, t_game *game, t_ray *ray)
{
	t_ground_ceiling	data;

	data.ceiling_y = column->start - 1;
	data.inverse_dist = (column->coords.y * ray->cos_angle_from_orientation) \
		/ (WIN_HEIGHT / 2) - ray->cos_angle_from_orientation;
	data.unit = ray->cos_angle_from_orientation / (WIN_HEIGHT / 2);
	data.ground_addr = t_mlx_get_pixel(game->mlx.img_buff, column->coords.x,
			column->coords.y);
	data.ceiling_addr = t_mlx_get_pixel(game->mlx.img_buff, column->coords.x,
			data.ceiling_y);
	while (column->coords.y < end)
	{
		get_pixel_position_in_tile(ray, &game->player.position,
			&data.pixel_pos, data.inverse_dist);
		draw_pixel_from_texture(&data.pixel_pos, data.ground_addr,
			game->animations[IDX_TXTR_FLOOR].textures->content, 1 / data.inverse_dist);
		if (data.ceiling_y >= 0)
			draw_pixel_from_texture(&data.pixel_pos, data.ceiling_addr,
				game->animations[IDX_TXTR_CEIL].textures->content, 1 / data.inverse_dist);
		column->coords.y++;
		data.ceiling_y--;
		data.inverse_dist += data.unit;
		data.ground_addr += game->mlx.img_buff->line_len;
		data.ceiling_addr -= game->mlx.img_buff->line_len;
	}
}
