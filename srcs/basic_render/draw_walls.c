/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:50:19 by brappo            #+#    #+#             */
/*   Updated: 2024/06/13 09:32:25 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 

#include "cub3d.h"

void	get_intersection(float angle, t_vector *position, t_map *map)
{
	float		length;
	t_vector	intersection;
	t_vector	slope;

	get_slope(&slope, angle);
	length = raycast(*position, &slope, map);
	vector_init(&intersection, position->x + position->x * length,
		position->y - position->y * length);
	printf("length = %f\n", length);
	vector_print("intersection : ", &intersection);
}

void	draw_walls(t_game *game)
{
	size_t		index;
	float		angle_by_pixel;
	float		angle;

	index = 0;
	angle_by_pixel = game->param.fov / (game->param.width -1);
	angle = game->player_rotation_rad + (game->param.fov / 2);
	while (index < game->param.width)
	{
		printf("angle degrees : %f\n", angle * 180 / PI);
		get_intersection(angle, &game->player_position, &game->map);
		angle -= angle_by_pixel;
		index++;
	}
}
