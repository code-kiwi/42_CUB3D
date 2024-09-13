/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lights_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:15:24 by brappo            #+#    #+#             */
/*   Updated: 2024/09/13 03:44:25 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "lights_bonus.h"

static bool	cast_light_rays(t_game *game, t_light *light)
{
	size_t	index;
	float	angle;
	float	angle_by_unit;
	t_ray	ray;
	size_t	lights_ray_count;

	lights_ray_count = 360 * LIGHT_RAY_BY_ANGLE;
	light->rays = ft_calloc(lights_ray_count, sizeof(float));
	if (light->rays == NULL)
		return (false);
	index = 0;
	angle = 0.0f;
	angle_by_unit = 2 * PI / lights_ray_count;
	while (index < lights_ray_count)
	{
		t_vector_get_slope(&ray.slope, angle);
		light->rays[index] = raycast(light->position, game, &ray, \
			LIGHT_DISTANCE);
		light->rays[index] *= light->rays[index];
		angle += angle_by_unit;
		index++;
	}
	return (true);
}

static bool	set_lights_values(t_game *game)
{
	size_t	index;
	t_map	*map;

	index = 0;
	map = game->map;
	while (index < map->lights_count)
	{
		if (!cast_light_rays(game, &map->lights[index]))
			return (false);
		index++;
	}
	return (true);
}

bool	init_lights(t_game *game)
{
	t_map		*map;

	if (game == NULL || game->map == NULL)
		return (false);
	map = game->map;
	map->lights_count = count_lights(map);
	if (map->lights_count == 0)
		return (true);
	if (!get_lights_position(map))
		return (false);
	if (!set_lights_values(game))
		return (false);
	return (true);
}
