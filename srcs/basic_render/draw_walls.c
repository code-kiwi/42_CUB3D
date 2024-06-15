/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/06/15 20:13:47 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

static void	draw_wall_column(size_t column, t_ray *ray, t_image *screen)
{
	float	perceived_height;
	int		wall_start;
	int		ground_start;

	perceived_height = WIN_HEIGHT;
	perceived_height /= (ray->length * cos(ray->angle_from_orientation));
	wall_start = floorf((WIN_HEIGHT - perceived_height) / 2);
	ground_start = floorf((WIN_HEIGHT + perceived_height) / 2);
	if (wall_start < 0)
		wall_start = 0;
	else
	{
		t_mlx_draw_line(screen, (t_mlx_coords){column, 0},
			(t_mlx_coords){column, wall_start - 1}, 0x00FF0000);
	}
	if (ground_start > WIN_HEIGHT)
		ground_start = WIN_HEIGHT;
	else
	{
		t_mlx_draw_line(screen, (t_mlx_coords){column, ground_start},
			(t_mlx_coords){column, WIN_HEIGHT}, 0x000000FF);
	}
	t_mlx_draw_line(screen, (t_mlx_coords){column, wall_start},
		(t_mlx_coords){column, ground_start - 1}, 0x0000FF00);
}

void	draw_walls(t_image *screen, t_ray *rays)
{
	size_t	index;

	index = 0;
	while (index < WIN_WIDTH)
	{
		draw_wall_column(index, &rays[index], screen);
		index++;
	}
}
