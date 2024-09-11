/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lightmap_values_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 05:27:28 by brappo            #+#    #+#             */
/*   Updated: 2024/09/11 08:48:20 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "lightmap_bonus.h"

#include <math.h>

static float	get_luminosity(t_game *game, t_vector *tile, t_vector *light)
{
	float	squared_distance;
	t_ray	ray;

	t_vector_init(&ray.slope, tile->x - light->x, light->y - tile->y);
	squared_distance = ray.slope.x * ray.slope.x + ray.slope.y * ray.slope.y;
	if (squared_distance >= LIGHT_SQUARED_DISTANCE)
		return (0.0f);
	ray.length = raycast(*light, game, &ray, LIGHT_SQUARED_DISTANCE);
	if (ray.length * ray.length + 0.1f < squared_distance)
		return (0.0f);
	return ((1 - squared_distance / LIGHT_SQUARED_DISTANCE) * 10);
}

static void	set_tile_value(t_game *game, t_mlx_coords *lightmap_coords, \
	t_vector *lights_pos, size_t lights_count)
{
	size_t		index;
	float		luminosity;
	t_vector	tile_pos;
	t_map		*map;

	index = 0;
	map = game->map;
	tile_pos.x = ((float)lightmap_coords->x + 0.5f) / LIGHTMAP_TILE_RATIO;
	tile_pos.y = ((float)lightmap_coords->y + 0.5f) / LIGHTMAP_TILE_RATIO;
	while (index < lights_count)
	{
		luminosity = get_luminosity(game, &tile_pos, &lights_pos[index]);
		if (luminosity > map->lightmap[lightmap_coords->y][lightmap_coords->x])
			map->lightmap[lightmap_coords->y][lightmap_coords->x] = luminosity;
		index++;
	}
}

void	set_lightmap_values(t_game *game, t_vector *lights_pos, \
	size_t lights_count)
{
	uint16_t		lines_count;
	uint16_t		line_length;
	t_mlx_coords	coords;
	t_map			*map;

	if (game == NULL || game->map == NULL || lights_pos == NULL)
		return ;
	map = game->map;
	lines_count = map->lines_count * LIGHTMAP_TILE_RATIO;
	coords.y = 0;
	while (coords.y < lines_count)
	{
		coords.x = 0;
		line_length = map->lines_lengths[(int)(coords.y / LIGHTMAP_TILE_RATIO)];
		line_length *= LIGHTMAP_TILE_RATIO;
		while (coords.x < line_length)
		{
			set_tile_value(game, &coords, lights_pos, lights_count);
			coords.x++;
		}
		coords.y++;
	}
}
