/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:14:16 by brappo            #+#    #+#             */
/*   Updated: 2024/09/05 14:29:30 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

#include <math.h>

static float	get_column_angle(t_ray *ray)
{
	float	column_angle;

	column_angle = atan2f(-ray->slope.y, ray->slope.x);
	if (column_angle < 0)
		column_angle += 2 * PI;
	else if (column_angle > 2 * PI)
		column_angle -= 2 * PI;
	return (column_angle);
}

static size_t	get_texture_start(t_player *player, t_image *sky_texture, \
	float perceived_height)
{
	size_t	texture_start;
	int		offset;
	float	scale_y;

	offset = player->camera_y - player->height;
	offset -= player->orientation.y;
	scale_y = sky_texture->height / perceived_height;
	texture_start = offset + sky_texture->height / 3 / scale_y;
	return (texture_start);
}

static void	draw_sky_column(size_t column_index, t_ray *ray, t_game *game)
{
	float		column_angle;
	t_column	column;
	t_image		*screen;
	t_image		*texture;

	column_angle = get_column_angle(ray);
	screen = game->mlx.img_buff;
	texture = game->anim[IDX_TXTR_SKY].textures->content;
	column.perceived_height = WIN_HEIGHT * 3;
	column.coords.y = 0;
	column.coords.x = column_index;
	column.texture_x = column_angle * (float)texture->width / (PI * 2);
	column.ranged_end = WIN_HEIGHT;
	column.texture_start = get_texture_start(&game->player, texture, \
		column.perceived_height);
	draw_texture_column(screen, &column, texture, 0);
}

void	draw_sky(t_game *game)
{
	size_t	index;
	t_image	*screen;
	t_ray	*ray;

	index = 0;
	screen = game->mlx.img_buff;
	while (index < WIN_WIDTH)
	{
		ray = &game->rays[index];
		draw_sky_column(index, ray, game);
		index++;
	}
}