/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:01:34 by root              #+#    #+#             */
/*   Updated: 2024/06/21 16:02:33 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "vector_bonus.h"
#include "map_bonus.h"

static void	calculate_unit_length(t_vector *unit_length, t_vector *slope)
{
	unit_length->x = sqrt(1 + pow((slope->y / slope->x), 2));
	unit_length->y = sqrt(1 + pow((slope->x / slope->y), 2));
}

static void	calculate_inital_sum(t_vector *sum_length, t_vector *unit_length,
	t_vector *position, t_vector *slope)
{
	if (slope->x < 0)
		sum_length->x = modff(position->x, &position->x);
	else
		sum_length->x = 1 - modff(position->x, &position->x);
	if (slope->y < 0)
		sum_length->y = 1 - modff(position->y, &position->y);
	else
		sum_length->y = modff(position->y, &position->y);
	sum_length->x *= unit_length->x;
	sum_length->y *= unit_length->y;
}

#include <stdio.h>

static bool	check_door(t_vector *position, t_game *game, t_ray *ray,
	float length,  bool is_vertical)
{
	t_vector	point_pos;
	double		temp;

	if (game->map.tiles[(int)position->y][(int)position->x] != ID_DOOR)
		return (false);
	point_pos.x = game->player.position.x + ray->slope.x * length;
	point_pos.y = game->player.position.y - ray->slope.y * length;
	if ((int)point_pos.x != position->x || (int)point_pos.y != position->y)
		return (false);
	if ((is_vertical && modf(point_pos.y, &temp) < game->door.transition)
		|| (!is_vertical && modf(point_pos.x, &temp) < game->door.transition))
		return (true);
	return (false);
}

float	raycast(t_vector position, t_vector *slope, t_game *game, t_ray *ray)
{
	t_vector	unit_length;
	t_vector	sum_length;

	calculate_unit_length(&unit_length, slope);
	calculate_inital_sum(&sum_length, &unit_length, &position, slope);
	while (sum_length.x < MAX_DISTANCE || sum_length.y < MAX_DISTANCE)
	{
		if (sum_length.x <= sum_length.y)
		{
			position.x += sign(slope->x);
			if (is_wall(&position, &game->map))
			{
				ray->is_vertical = true;
				return (sum_length.x);
			}
			if (check_door(&position, game, ray, sum_length.x + unit_length.x / 2, true))
			{
				ray->is_vertical = true;
				ray->is_door = true;
				return (sum_length.x + unit_length.x / 2);
			}
			sum_length.x += unit_length.x;
		}
		else
		{
			position.y -= sign(slope->y);
			if (is_wall(&position, &game->map))
			{
				ray->is_vertical = false;
				return (sum_length.y);
			}
			if (check_door(&position, game, ray, sum_length.y + unit_length.y / 2, false))
			{
				ray->is_vertical = false;
				ray->is_door = true;
				return (sum_length.y + unit_length.y / 2);
			}
			sum_length.y += unit_length.y;
		}
	}
	return (MAX_DISTANCE);
}
