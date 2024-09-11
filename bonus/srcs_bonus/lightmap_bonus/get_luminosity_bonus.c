/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_luminosity_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:27:48 by brappo            #+#    #+#             */
/*   Updated: 2024/09/11 10:40:55 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lightmap_bonus.h"
#include "cub3d_bonus.h"

float	get_luminosity(t_vector *position, float **lightmap, float distance)
{
	t_mlx_coords	lightmap_coords;
	float			distance_factor;

	if (distance >= MAX_VISION_DISTANCE)
		return (0.0f);
	lightmap_coords.x = position->x * LIGHTMAP_TILE_RATIO;
	lightmap_coords.y = position->y * LIGHTMAP_TILE_RATIO;
	distance_factor = 1 - distance / MAX_VISION_DISTANCE;
	return (lightmap[lightmap_coords.y][lightmap_coords.x] * distance_factor);
}
