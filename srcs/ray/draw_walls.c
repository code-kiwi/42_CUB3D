/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:50:19 by brappo            #+#    #+#             */
/*   Updated: 2024/06/14 13:02:30 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 

#include "cub3d.h"

static void	get_intersection(float angle, t_vector *position, t_map *map)
{
	float		length;
	t_vector	intersection;
	t_vector	slope;

	t_vector_get_slope(&slope, angle);
	length = raycast(*position, &slope, map);
	t_vector_init(&intersection, position->x + position->x * length,
		position->y - position->y * length);
	printf("length = %f\n", length);
	t_vector_print("intersection : ", &intersection);
}

void	draw_walls(t_player *player, t_map *map)
{
	size_t		index;
	float		angle_by_pixel;
	float		angle;

	index = 0;
	angle_by_pixel = player->fov_angle / (WIN_WIDTH - 1);
	angle = player->orientation + (player->fov_angle / 2);
	while (index < WIN_WIDTH)
	{
		printf("angle degrees : %f\n", angle * 180 / PI);
		get_intersection(angle, &player->position, map);
		angle -= angle_by_pixel;
		index++;
	}
}
