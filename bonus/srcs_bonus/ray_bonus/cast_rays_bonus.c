/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:50:19 by brappo            #+#    #+#             */
/*   Updated: 2024/06/30 09:41:29 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "cub3d_bonus.h"

static bool	set_ray(t_ray *result, float angle, t_game *game)
{
	float		intersection_x;
	float		intersection_y;
	t_player	*player;

	player = &game->player;
	result->is_door = false;
	t_vector_get_slope(&result->slope, angle);
	result->length = raycast(player->position, game, result, MAX_DISTANCE);
	intersection_x = player->position.x + result->slope.x * result->length;
	intersection_y = player->position.y - result->slope.y * result->length;
	t_vector_init(&result->intersection, intersection_x, intersection_y);
	result->angle_from_orientation = fabsf(player->orientation - angle);
	result->cos_angle_from_orientation = cos(result->angle_from_orientation);
	if (!result->is_door)
		result->door = NULL;
	return (true);
}

bool	cast_rays(t_game *game)
{
	size_t		index;
	float		angle;
	float		angle_by_pixel;
	t_player	*player;

	index = 0;
	player = &game->player;
	angle_by_pixel = player->fov_angle / (WIN_WIDTH - 1);
	angle = player->orientation + (player->fov_angle / 2);
	player->leftmost_angle = angle;
	while (index < WIN_WIDTH)
	{
		if (!set_ray(&game->rays[index], angle, game))
			return (false);
		angle -= angle_by_pixel;
		index++;
	}
	return (true);
}
