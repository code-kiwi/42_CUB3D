/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:14:16 by brappo            #+#    #+#             */
/*   Updated: 2024/09/05 14:20:40 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

#include <math.h>

void	draw_sky_column(t_image *screen, float angle, t_image *texture, \
	int column_index, int offset)
{
	char			*addr;
	char			*color_addr;
	int				index;
	float			texture_pos;
	float			scale_y;
	unsigned int	color;

	index = 0;
	addr = t_mlx_get_pixel(screen, column_index, 0);
	scale_y = (float)texture->height / 3 / WIN_HEIGHT;
	color_addr = t_mlx_get_pixel(texture, angle * (float)texture->width / (PI * 2), texture->height / 3);
	texture_pos = offset * scale_y;
	while (index < WIN_HEIGHT)
	{
		color = *(unsigned int *)(color_addr + \
			(int)texture_pos * texture->line_len);
		*(unsigned int *)addr = color;
		texture_pos += scale_y;
		index++;
		addr += screen->line_len;
	}
}

void	draw_sky_column_temp(size_t column_index, t_ray *ray, t_game *game)
{
	int			offset;
	float		column_angle;
	t_column	column;
	t_image		*screen;
	t_image		*texture;
	float		scale_y;

	column_angle = atan2f(-ray->slope.y, ray->slope.x);
	if (column_angle < 0)
		column_angle += 2 * PI;
	else if (column_angle > 2 * PI)
		column_angle -= 2 * PI;
	screen = game->mlx.img_buff;
	texture = game->anim[IDX_TXTR_SKY].textures->content;
	offset = game->player.camera_y - game->player.height;
	offset -= game->player.orientation.y;
	column.perceived_height = WIN_HEIGHT * 3;
	column.coords.y = 0;
	column.coords.x = column_index;
	column.texture_x = column_angle * (float)texture->width / (PI * 2);
	column.ranged_end = WIN_HEIGHT;
	scale_y = texture->height / column.perceived_height;
	column.texture_start = offset + texture->height / 3 / scale_y;
	draw_texture_column(screen, &column, texture, ray->length);
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
		draw_sky_column_temp(index, ray, game);
		index++;
	}
}