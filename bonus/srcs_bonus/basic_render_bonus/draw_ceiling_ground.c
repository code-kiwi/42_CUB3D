/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_ground.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:24:21 by brappo            #+#    #+#             */
/*   Updated: 2024/06/19 15:03:04 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"
#include "cub3d_bonus.h"

#include <math.h>

#include <stdio.h>

static	void	get_pixel_position_in_tile(t_mlx_coords *coords, t_ray *ray,
	t_vector *player_position, t_vector *result)
{
	float		straight_line_dist;
	float		pixel_dist;
	double		temp;

	straight_line_dist = (float)(WIN_HEIGHT / 2) / (coords->y - WIN_HEIGHT / 2);
	pixel_dist = straight_line_dist / ray->cos_angle_from_orientation;
	result->x = player_position->x + ray->slope.x * pixel_dist;
	result->y = player_position->y - ray->slope.y * pixel_dist;
	result->x = modf(result->x, &temp);
	result->y = modf(result->y, &temp);
}

static void	draw_pixel_from_texture(t_vector *pos_in_tile, char *addr,
	t_image *texture)
{
	t_mlx_coords	color_coords;
	char			*color;

	color_coords.x = pos_in_tile->x * texture->width;
	color_coords.y = pos_in_tile->y * texture->height;
	color = t_mlx_get_pixel(texture, color_coords.x, color_coords.y);
	*(unsigned int *)addr = *(unsigned int *)color;
}

void	draw_ground_ceiling(t_column *column, int end, t_game *game, t_ray *ray)
{
	t_vector		pixel_pos;
	t_mlx_coords	ceiling;
	char			*ground_addr;
	char			*ceiling_addr;
	t_image			*screen;

	ceiling.x = column->coords.x;
	ceiling.y = column->wall_start - 1;
	screen = game->mlx.img_buff;
	ground_addr = t_mlx_get_pixel(screen, column->coords.x, column->coords.y);
	ceiling_addr = t_mlx_get_pixel(screen, ceiling.x, ceiling.y);
	while (column->coords.y < end)
	{
		get_pixel_position_in_tile(&column->coords, ray, &game->player.position,
			&pixel_pos);
		draw_pixel_from_texture(&pixel_pos, ground_addr, &game->textures[4]);
		if (ceiling.y >= 0)
			draw_pixel_from_texture(&pixel_pos, ceiling_addr,
				&game->textures[5]);
		column->coords.y++;
		ceiling.y--;
		ground_addr += game->mlx.img_buff->line_len;
		ceiling_addr -= game->mlx.img_buff->line_len;
	}
}
