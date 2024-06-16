/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:23:55 by root              #+#    #+#             */
/*   Updated: 2024/06/16 15:28:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>

char	*get_color(t_image *image, size_t x, size_t y)
{
	return (image->addr + x * image->line_len + y * (image->bpp / 8));
}

bool	t_mlx_draw_pixel_2(t_image *img, t_mlx_coords *coords,
	unsigned int color)
{
	char	*dest;

	dest = img->addr + (coords->y * img->line_len + coords->x * img->bpp / 8);
	*(unsigned int *) dest = color;
	return (true);
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

bool	draw_texture_column(t_image *screen, t_column *column, int wall_end)
{
	char		*color;
	int			texture_column;
	float		scale_y;

	texture_column = pixel_column_on_texture(column->ray,
			column->texture->width);
	scale_y = column->perceived_height / column->texture->height;
	while (column->coords.y < wall_end)
	{
		color = get_color(column->texture, texture_column,
				(int)floor(column->texture_start / scale_y));
		if (!t_mlx_draw_pixel_2(screen, &column->coords, *color))
			return (false);
		column->coords.y++;
		column->texture_start++;
	}
	return (true);
}

bool	draw_color_column(t_image *screen, t_mlx_coords *coords,
	unsigned int color, int end)
{
	while (coords->y < end)
	{
		if (!t_mlx_draw_pixel_2(screen, coords, color))
			return (false);
		coords->y++;
	}
	return (true);
}
