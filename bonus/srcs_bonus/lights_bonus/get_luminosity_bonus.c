/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_luminosity_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:27:48 by brappo            #+#    #+#             */
/*   Updated: 2024/09/11 10:23:09by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lights_bonus.h"
#include "cub3d_bonus.h"

#include <math.h>

static float	get_light_luminosity(t_light *light, t_vector *position)
{
	float		position_angle;
	float		squared_distance;
	t_vector	light_to_pos;
	size_t		ray_index;

	squared_distance = get_squared_distance(&light->position, position);
	if (squared_distance > LIGHT_SQUARED_DISTANCE)
		return (0.0f);
	light_to_pos.x = position->x - light->position.x;
	light_to_pos.y = light->position.y - position->y;
	position_angle = atan2(light_to_pos.y, light_to_pos.x);
	ray_index = position_angle * LIGHT_RAY_BY_ANGLE;
	if (light->rays[ray_index] + 0.1f < squared_distance)
		return (0.0f);
	return (1 - squared_distance / LIGHT_SQUARED_DISTANCE);
}

float	get_luminosity(t_vector *position, t_map *map, float distance)
{
	float	luminosity;
	float	distance_factor;
	size_t	index;

	if (is_sky(position, map))
		luminosity = SKY_LUMINOSITY;
	else
		luminosity = DEFAULT_LUMINOSITY;
	index = 0;
	distance_factor = 1 - distance / MAX_VISION_DISTANCE;
	while (index < map->lights_count)
	{
		luminosity += get_light_luminosity(&map->lights[index], position);
		if (luminosity >= 1)
			return (luminosity * distance_factor);
		index++;
	}
	return (luminosity * distance_factor);
}
