/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/06/14 15:08:22 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "math.h"

static bool	draw_wall_column(size_t column, t_ray *ray, t_image *screen)
{
	float	perceived_height;
	int		wall_start;
	int		ground_start;
	bool	error;

	error = false;
	perceived_height = WIN_HEIGHT;
	perceived_height /= (ray->length * cos(ray->angle_from_orientation));
	wall_start = floorf((WIN_HEIGHT - perceived_height) / 2);
	ground_start = floorf((WIN_HEIGHT + perceived_height) / 2);
	if (wall_start < 0)
		wall_start = 0;
	else
	{
		error = t_mlx_draw_line(screen, (t_mlx_coords){column, 0},
				(t_mlx_coords){column, wall_start - 1}, 0x00FF0000);
	}
	if (ground_start > WIN_HEIGHT)
		ground_start = WIN_HEIGHT;
	else
	{
		error = (t_mlx_draw_line(screen, (t_mlx_coords){column, ground_start},
					(t_mlx_coords){column, WIN_HEIGHT}, 0x000000FF)) | error;
	}
	error = (t_mlx_draw_line(screen, (t_mlx_coords){column, wall_start},
				(t_mlx_coords){column, ground_start - 1}, 0x0000FF00)) | error;
	return (error);
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