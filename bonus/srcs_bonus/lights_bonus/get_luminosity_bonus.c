/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_luminosity_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:27:48 by brappo            #+#    #+#             */
/*   Updated: 2024/09/14 11:49:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lights_bonus.h"
#include "cub3d_bonus.h"

#include <math.h>

static float	get_position_angle(t_vector *light_pos, t_vector *position)
{
	float		position_angle;
	t_vector	light_to_pos;

	light_to_pos.x = position->x - light_pos->x;
	light_to_pos.y = light_pos->y - position->y;
	position_angle = atan2(light_to_pos.y, light_to_pos.x);
	if (position_angle < 0)
		position_angle += 2 * PI;
	else if (position_angle > 2 * PI)
		position_angle -= 2 * PI;
	return (position_angle);
}

static float	get_light_luminosity(t_light *light, t_vector *position)
{
	float		position_angle;
	float		squared_distance;
	size_t		ray_index;

	squared_distance = get_squared_distance(&light->position, position);
	if (squared_distance > LIGHT_SQUARED_DISTANCE)
		return (0.0f);
	position_angle = get_position_angle(&light->position, position);
	ray_index = position_angle * LIGHT_RAY_BY_ANGLE;
	if (light->rays[ray_index] + LIGHT_ACCEPTED_ERROR < squared_distance)
		return (0.0f);
	return (1.0f - squared_distance / LIGHT_SQUARED_DISTANCE);
}

float	get_luminosity(t_vector *position, t_map *map, float inv_dist)
{
	float	luminosity;
	float	distance_factor;
	size_t	index;

	if (is_sky(position, map))
		luminosity = SKY_LUMINOSITY;
	else
		luminosity = DEFAULT_LUMINOSITY;
	index = 0;
	distance_factor = 1 - 1 / (inv_dist * MAX_VISION_DISTANCE);
	while (index < map->lights_count)
	{
		luminosity += get_light_luminosity(&map->lights[index], position);
		if (luminosity >= 1.0f)
			return (1.0f * distance_factor);
		index++;
	}
	return (luminosity * distance_factor);
}
