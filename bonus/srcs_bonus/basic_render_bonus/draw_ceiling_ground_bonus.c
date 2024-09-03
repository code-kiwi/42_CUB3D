/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_ground_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:24:21 by brappo            #+#    #+#             */
/*   Updated: 2024/07/31 12:07:48by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

# define PLAYER_HEIGHT_DIFF WIN_HEIGHT / 4
// # define PLAYER_HEIGHT_DIFF 0

static	void	get_pixel_position_in_tile(t_ray *ray,
	t_vector *player_position, t_vector *result, float dist)
{
	result->x = player_position->x + ray->slope.x * dist;
	result->y = player_position->y - ray->slope.y * dist;
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

void	draw_ground(t_column *column, int start, t_game *game, t_ray *ray)
{
	t_vector	pixel_position;
	char		*addr;
	float		distance;

	addr = t_mlx_get_pixel(game->mlx.img_buff, column->coords.x, start);
	while (start < WIN_HEIGHT)
	{
		distance = WIN_HEIGHT / 2 - PLAYER_HEIGHT_DIFF;
		distance /= (column->real_ground_start - WIN_HEIGHT / 2);
		distance /= ray->cos_angle_from_orientation;
		get_pixel_position_in_tile(ray, &game->player.position,
			&pixel_position, distance);
		draw_pixel_from_texture(&pixel_position, addr,
			game->anim[IDX_TXTR_FLOOR].textures->content, distance);
		column->real_ground_start++;
		start++;
		addr += game->mlx.img_buff->line_len;
	}
}

void	draw_ceiling(t_column *column, int start, t_game *game, t_ray *ray)
{
	t_vector	pixel_position;
	char		*addr;
	float		distance;

	addr = t_mlx_get_pixel(game->mlx.img_buff, column->coords.x, start);
	while (start >= 0)
	{
		distance = WIN_HEIGHT / 2 - PLAYER_HEIGHT_DIFF;
		distance /= (column->real_ceiling_start - WIN_HEIGHT / 2);
		distance /= ray->cos_angle_from_orientation;
		get_pixel_position_in_tile(ray, &game->player.position,
			&pixel_position, distance);
		draw_pixel_from_texture(&pixel_position, addr,
			game->anim[IDX_TXTR_CEIL].textures->content, distance);
		start--;
		column->real_ceiling_start++;
		addr -= game->mlx.img_buff->line_len;
	}
}
