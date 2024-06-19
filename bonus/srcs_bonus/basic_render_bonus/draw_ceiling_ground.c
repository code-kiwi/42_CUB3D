/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_ground.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:24:21 by brappo            #+#    #+#             */
/*   Updated: 2024/06/19 14:25:10 by brappo           ###   ########.fr       */
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

static void	draw_pixel_from_texture(t_vector *pos_in_tile,
	t_mlx_coords *screen_coords, t_image *texture, t_image *screen)
{
	t_mlx_coords	color_coords;
	char			*color;

	color_coords.x = pos_in_tile->x * texture->width;
	color_coords.y = pos_in_tile->y * texture->height;
	color = t_mlx_get_pixel(texture, color_coords.x, color_coords.y);
	t_mlx_draw_pixel(screen, screen_coords, *(unsigned int *)color);
}

void	draw_ground(t_mlx_coords *coords, int end, t_game *game, t_ray *ray)
{
	t_vector	pixel_pos;

	while (coords->y < end)
	{
		get_pixel_position_in_tile(coords, ray, &game->player.position,
			&pixel_pos);
		draw_pixel_from_texture(&pixel_pos, coords, &game->textures[4],
			game->mlx.img_buff);
		coords->y++;
	}
}
