/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:06:07 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/19 16:06:13 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

static bool	set_ray(t_ray *result, float angle, t_player *player, t_map *map)
{
	float	intersection_x;
	float	intersection_y;

	t_vector_get_slope(&result->slope, angle);
	result->length = raycast(player->position, &result->slope, map,
			&result->is_vertical);
	intersection_x = player->position.x + result->slope.x * result->length;
	intersection_y = player->position.y - result->slope.y * result->length;
	t_vector_init(&result->intersection, intersection_x, intersection_y);
	result->angle_from_orientation = fabsf(player->orientation - angle);
	return (true);
}

bool	cast_rays(t_player *player, t_map *map, t_ray *rays)
{
	size_t		index;
	float		angle_by_pixel;
	float		angle;

	index = 0;
	angle_by_pixel = player->fov_angle / (WIN_WIDTH - 1);
	angle = player->orientation + (player->fov_angle / 2);
	while (index < WIN_WIDTH)
	{
		if (!set_ray(&rays[index], angle, player, map))
			return (false);
		angle -= angle_by_pixel;
		index++;
	}
	return (true);
}
