/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lightmap_values_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 05:27:28 by brappo            #+#    #+#             */
/*   Updated: 2024/09/12 06:12:35 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "lightmap_bonus.h"

#include <math.h>

static float	get_light_luminosity(t_game *game, t_vector *tile, \
	t_vector *light)
{
	float	squared_distance;
	t_ray	ray;
	char	character;

	ray.slope.x = tile->x - light->x;
	ray.slope.y = light->y - tile->y;
	character = game->map->tiles[(int)tile->y][(int)tile->x];
	if (character != ID_MAP_DOOR_CLOSED
		&& character != ID_MAP_DOOR_CLOSED - 32)
	{
		if (light->x > tile->x)
			ray.slope.x += 1.0f / LIGHTMAP_TILE_RATIO;
		if (light->y > tile->y)
			ray.slope.y -= 1.0f / LIGHTMAP_TILE_RATIO;
	}
	squared_distance = ray.slope.x * ray.slope.x + ray.slope.y * ray.slope.y;
	if (squared_distance >= LIGHT_SQUARED_DISTANCE)
		return (0.0f);
	ray.length = raycast(*light, game, &ray, LIGHT_SQUARED_DISTANCE);
	if (ray.length * ray.length + 0.1f < squared_distance)
		return (0.0f);
	return (1 - squared_distance / LIGHT_SQUARED_DISTANCE);
}

static void	set_tile_value(t_game *game, t_mlx_coords *lightmap_coords, \
	t_vector *lights_pos, size_t lights_count)
{
	size_t		index;
	t_vector	tile_pos;
	t_map		*map;
	float		*luminosity;

	index = 0;
	map = game->map;
	luminosity = &map->lightmap[lightmap_coords->y][lightmap_coords->x];
	tile_pos.x = (float)lightmap_coords->x / LIGHTMAP_TILE_RATIO;
	tile_pos.y = (float)lightmap_coords->y / LIGHTMAP_TILE_RATIO;
	if (is_sky(&tile_pos, game->map))
		*luminosity = SKY_LUMINOSITY;
	else
		*luminosity = DEFAULT_LUMINOSITY;
	while (index < lights_count)
	{
		*luminosity += get_light_luminosity(game, &tile_pos, &lights_pos[index]);
		if (*luminosity >= 1.0f)
		{
			*luminosity = 1.0f;
			return ;
		}
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
