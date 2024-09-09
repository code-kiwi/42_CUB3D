/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lightning_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 06:22:00 by brappo            #+#    #+#             */
/*   Updated: 2024/09/09 13:16:50 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lightmaps_bonus.h"
#include "cub3d_bonus.h"

static void	calculate_lightning_ray(float angle, t_vector *position, \
	t_game *game, float **lightmap)
{
	t_vector	ray_slope;
	t_ray		ray;
	float		distance;

	t_vector_get_slope(&ray_slope, angle);
	distance = raycast(*position, game, &ray, LIGHT_RADIUS);
	(void)distance;
	(void)lightmap;
}

void	calculate_lightning(float **lightmap, size_t x, size_t y, t_game *game)
{
	float		angle;
	float		angle_unit;
	t_vector	position;

	position.x = x * LIGHTMAP_TILE_RATIO + LIGHTMAP_TILE_RATIO / 2;
	position.y = y * LIGHTMAP_TILE_RATIO + LIGHTMAP_TILE_RATIO / 2;
	angle = 0;
	angle_unit = 2 * PI / 360;
	while (angle < 2 * PI)
	{
		calculate_lightning_ray(angle, &position, game, lightmap);
		angle += angle_unit;
		angle++;
	}
}
