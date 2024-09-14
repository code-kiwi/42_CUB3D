/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lights_values_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 03:47:27 by brappo            #+#    #+#             */
/*   Updated: 2024/09/14 10:49:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "lights_bonus.h"
#include "libft.h"

static bool	cast_light_rays(t_game *game, t_light *light)
{
	size_t	index;
	float	angle;
	float	angle_by_unit;
	t_ray	ray;
	size_t	lights_ray_count;

	lights_ray_count = 2 * PI * LIGHT_RAY_BY_ANGLE;
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

bool	set_lights_values(t_game *game)
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