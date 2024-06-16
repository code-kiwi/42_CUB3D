/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/06/16 15:04:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "math.h"
#include <stdio.h>

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

char	*get_color(t_image *image, size_t x, size_t y)
{
	return (image->addr + x * image->line_len + y * (image->bpp / 8));
}

static bool	draw_texture_column(t_image *screen, t_wall_column *wall_column)
{
	char		*color;
	int			texture_column;
	int			ground_start;
	float		scale_y;

	texture_column = pixel_column_on_texture(wall_column->ray,
			wall_column->texture->width);
	ground_start = min(floorf((WIN_HEIGHT + wall_column->perceived_height) / 2),
			WIN_HEIGHT);
	scale_y = wall_column->perceived_height / wall_column->texture->height;
	while (wall_column->coords.y < ground_start)
	{
		color = get_color(wall_column->texture, texture_column,
				(int)floor(wall_column->texture_start / scale_y));
		if (!t_mlx_draw_pixel_2(screen, &wall_column->coords, *color))
			return (false);
		wall_column->coords.y++;
		wall_column->texture_start++;
	}
	return (true);
}

static bool	draw_wall_column(size_t column, t_ray *ray, t_image *screen,
	t_image *texture)
{
	t_wall_column	wall_column;
	int				wall_start;

	wall_column.texture = texture;
	wall_column.perceived_height = WIN_HEIGHT
		/ (ray->length * cos(ray->angle_from_orientation));
	wall_column.coords.y = 0;
	wall_column.coords.x = column;
	wall_column.ray = ray;
	wall_start = floorf((WIN_HEIGHT - wall_column.perceived_height) / 2);
	while (wall_column.coords.y < wall_start)
	{
		if (!t_mlx_draw_pixel_2(screen, &wall_column.coords, 0x00FF0000))
			return (false);
		wall_column.coords.y++;
	}
	wall_column.texture_start = wall_column.coords.y - wall_start;
	draw_texture_column(screen, &wall_column);
	while (wall_column.coords.y < WIN_HEIGHT)
	{
		if (!t_mlx_draw_pixel_2(screen, &wall_column.coords, 0x000000FF))
			return (false);
		wall_column.coords.y++;
	}
	return (true);
}

bool	draw_walls(t_image *screen, t_ray *rays, t_image *texture)
{
	size_t	index;

	index = 0;
	while (index < WIN_WIDTH)
	{
		if (!draw_wall_column(index, &rays[index], screen, texture))
			return (false);
		index++;
	}
	return (true);
}
