/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/06/16 13:26:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "math.h"
#include <stdio.h>

#define SCREEN_DISTANCE 1

bool	t_mlx_draw_pixel_2(t_image *img, t_mlx_coords *coords, unsigned int color)
{
	char	*dest;

	dest = img->addr + (coords->y * img->line_len + coords->x * img->bpp / 8);
	*(unsigned int *) dest = color;
	return (true);
}

static bool	draw_texture_column(t_image *screen, t_mlx_coords *start, int end, t_image *texture, int texture_column, float perceived_height, int diff)
{
	bool		error;
	char		*color;
	float		scale_y;

	scale_y = perceived_height / texture->height;
	error = false;
	while (start->y < end)
	{
		color = texture->addr + (texture_column * texture->line_len + (int)floor(diff / scale_y) * (texture->bpp / 8));
		error = !t_mlx_draw_pixel_2(screen, start, *color) | error;
		start->y++;
		diff++;
	}
	return (!error);
}

int	pixel_column_on_texture(t_ray *ray, int texture_width)
{
	int		column;
	float	texture_relative_position;
	double	temp;

	if (ray->is_vertical)
		texture_relative_position = modf(ray->intersection.y, &temp);
	else
		texture_relative_position = modf(ray->intersection.x, &temp);
	column = floorf(texture_relative_position * texture_width);
	return(column);
}

static bool	draw_wall_column(size_t column, t_ray *ray, t_image *screen, t_image *texture)
{
	float	perceived_height;
	int		wall_start;
	int		ground_start;
	bool	error;
	t_mlx_coords	coords;

	perceived_height = WIN_HEIGHT * SCREEN_DISTANCE;
	perceived_height /= (ray->length * cos(ray->angle_from_orientation));
	wall_start = floorf((WIN_HEIGHT - perceived_height) / 2);
	ground_start = floorf((WIN_HEIGHT + perceived_height) / 2);
	if (ground_start > WIN_HEIGHT)
		ground_start = WIN_HEIGHT;
	coords.x = column;
	coords.y = 0;
	error = false;
	while (coords.y < wall_start)
	{
		error = !t_mlx_draw_pixel_2(screen, &coords, 0x00FF0000) | error;
		coords.y++;
	}
	draw_texture_column(screen, &coords, ground_start, texture, pixel_column_on_texture(ray, texture->width), perceived_height, coords.y - wall_start);
	while (coords.y < WIN_HEIGHT)
	{
		error = !t_mlx_draw_pixel_2(screen, &coords, 0x000000FF) | error;
		coords.y++;
	}
	return (!error);
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