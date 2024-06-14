/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:50:19 by brappo            #+#    #+#             */
/*   Updated: 2024/06/14 14:57:01 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

static void	set_ray(t_ray *result, float angle, t_player *player, t_map *map)
{
	float	intersection_x;
	float	intersection_y;

	t_vector_get_slope(&result->slope, angle);
	result->length = raycast(player->position, &result->slope, map);
	intersection_x = player->position.x + player->position.x * result->length;
	intersection_y = player->position.y - player->position.y * result->length;
	t_vector_init(&result->intersection, intersection_x, intersection_y);
	result->angle_from_orientation = fabsf(player->orientation - angle);
}

void	cast_rays(t_player *player, t_map *map, t_ray *rays)
{
	size_t		index;
	float		angle_by_pixel;
	float		angle;

	index = 0;
	angle_by_pixel = player->fov_angle / (WIN_WIDTH - 1);
	angle = player->orientation + (player->fov_angle / 2);
	while (index < WIN_WIDTH)
	{
		set_ray(&rays[index], angle, player, map);
		angle -= angle_by_pixel;
		index++;
	}
}
