/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/06/14 16:17:11 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "math.h"
#include <stdio.h>

bool	t_mlx_draw_pixel_2(t_image *img, t_mlx_coords *coords, unsigned int color)
{
	char	*dest;

	dest = img->addr + (coords->y * img->line_len + coords->x * img->bpp / 8);
	*(unsigned int *) dest = color;
	return (true);
}


static bool	draw_wall_column(size_t column, t_ray *ray, t_image *screen)
{
	float	perceived_height;
	int		wall_start;
	int		ground_start;
	bool	error;
	t_mlx_coords	coords;

	error = false;
	perceived_height = WIN_HEIGHT;
	perceived_height /= (ray->length * cos(ray->angle_from_orientation));
	wall_start = floorf((WIN_HEIGHT - perceived_height) / 2);
	ground_start = floorf((WIN_HEIGHT + perceived_height) / 2);
	if (ground_start > WIN_HEIGHT)
		ground_start = WIN_HEIGHT;
	coords.x = column;
	coords.y = 0;
	while (coords.y < wall_start)
	{
		t_mlx_draw_pixel_2(screen, &coords, 0x00FF0000);
		coords.y++;
	}
	while (coords.y < ground_start)
	{
		t_mlx_draw_pixel_2(screen, &coords, 0x0000FF00);
		coords.y++;
	}
	while (coords.y < WIN_HEIGHT)
	{
		t_mlx_draw_pixel_2(screen, &coords, 0x000000FF);
		coords.y++;
	}
	return (true);
}

bool	draw_walls(t_image *screen, t_ray *rays)
{
	size_t	index;

	index = 0;
	while (index < WIN_WIDTH)
	{
		if (!draw_wall_column(index, &rays[index], screen))
			return (false);
		index++;
	}
	return (true);
}