/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:23:55 by root              #+#    #+#             */
/*   Updated: 2024/06/18 12:19:19 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>

static t_image	*get_texture(t_image textures[4], t_ray *ray)
{
	if (ray->is_vertical)
	{
		if (ray->slope.x > 0)
			return (&textures[3]);
		else
			return (&textures[1]);
	}
	else
	{
		if (ray->slope.y > 0)
			return (&textures[2]);
		else
			return (&textures[0]);
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
	column = floorf(texture_relative_position * texture_width);
	return (column);
}

void	draw_texture_column(t_image *screen, t_column *column, int wall_end,
	t_image textures[4])
{
	char	*color;
	int		texture_column;
	float	scale_y;
	t_image	*texture;
	char	*addr;

	texture = get_texture(textures, column->ray);
	texture_column = pixel_column_on_texture(column->ray, texture->width);
	scale_y = column->perceived_height / texture->height;
	addr = screen->addr + (column->coords.y * screen->line_len \
		+ column->coords.x * screen->bpp / 8);
	color = texture->addr + texture_column * (screen->bpp / 8);
	while (column->coords.y < wall_end)
	{
		// color = t_mlx_get_pixel(texture, texture_column,
		// 		(int)floor(column->texture_start / scale_y));
		*(unsigned int *)addr = *(unsigned int *)(color \
			+ (int)floor(column->texture_start / scale_y) * texture->line_len);
		addr += screen->line_len;
		column->coords.y++;
		column->texture_start++;
	}
}

void	draw_color_column(t_image *screen, t_mlx_coords *coords,
	unsigned int color, int end)
{
	char	*addr;

	addr = screen->addr + (coords->y * screen->line_len \
		+ coords->x * screen->bpp / 8);
	while (coords->y < end)
	{
		*(unsigned int *)addr = color;
		addr += screen->line_len;
		coords->y++;
	}
}
