/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_ground.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:55:51 by brappo            #+#    #+#             */
/*   Updated: 2024/06/19 13:55:34by brappo           ###   ########.fr       */
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
	pixel_dist = straight_line_dist / cos(ray->angle_from_orientation);
	result->x = player_position->x + ray->slope.x * pixel_dist;
	result->y = player_position->y - ray->slope.y * pixel_dist;
	result->x = modf(result->x, &temp);
	result->y = modf(result->y, &temp);
}

static void	draw_pixel_ground(t_mlx_coords *coords, t_game *game, t_ray *ray)
{
	t_vector		pixel_pos;
	char			*color;
	t_mlx_coords	color_coords;

	get_pixel_position_in_tile(coords, ray, &game->player.position, &pixel_pos);
	color_coords.x = pixel_pos.x * game->textures[4].width;
	color_coords.y = pixel_pos.y * game->textures[3].width;
	color = t_mlx_get_pixel(&game->textures[4], color_coords.x, color_coords.y);
	t_mlx_draw_pixel(game->mlx.img_buff, coords, *(unsigned int *)color);
}

void	draw_ground(t_mlx_coords *coords, int end, t_game *game, t_ray *ray)
{
	while (coords->y < end)
	{
		draw_pixel_ground(coords, game, ray);
		coords->y++;
	}
}
