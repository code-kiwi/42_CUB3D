/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:50:19 by brappo            #+#    #+#             */
/*   Updated: 2024/06/12 19:24:02 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h> 

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
	angle_by_pixel = game->param.fov / game->param.width;
	angle = game->player_rotation_rad + game->param.fov / 2;
	while (index < game->param.width)
	{
		get_intersection(angle, &game->player_position, &game->map);
		angle += angle_by_pixel;
		index++;
	}
}
