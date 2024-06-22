/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:01:34 by root              #+#    #+#             */
/*   Updated: 2024/06/22 15:52:39 by brappo           ###   ########.fr       */
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

static bool	check_door(t_vector *pos, t_game *game, t_ray *ray,
	float length,  bool is_vertical)
{
	t_vector		point_pos;
	t_mlx_coords	map_pos;
	double			temp;
	t_door			*door;

	if (game->map.tiles[(int)pos->y][(int)pos->x] != ID_DOOR_CLOSED
		&& game->map.tiles[(int)pos->y][(int)pos->x] != ID_DOOR_OPENED)
		return (false);
	point_pos.x = game->player.position.x + ray->slope.x * length;
	point_pos.y = game->player.position.y - ray->slope.y * length;
	map_pos.x = point_pos.x;
	map_pos.y = point_pos.y;
	if (map_pos.x != pos->x || map_pos.y != pos->y)
		return (false);
	door = find_door_at_position(&map_pos, game->doors, game->door_count);
	if (door == NULL)
		return (false);
	if ((is_vertical && modf(point_pos.y, &temp) < door->transition)
		|| (!is_vertical && modf(point_pos.x, &temp) < door->transition))
	{
		ray->door = door;
		return (true);
	}
	return (false);
}

float	raycast(t_vector position, t_game *game, t_ray *ray)
{
	t_vector	unit_length;
	t_vector	sum_length;

	calculate_unit_length(&unit_length, &ray->slope);
	calculate_inital_sum(&sum_length, &unit_length, &position, &ray->slope);
	while (sum_length.x < MAX_DISTANCE || sum_length.y < MAX_DISTANCE)
	{
		if (sum_length.x <= sum_length.y)
		{
			position.x += sign(ray->slope.x);
			if (!is_in_bounds(&position, &game->map)
				|| is_character(&position, &game->map, ID_WALL))
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
			position.y -= sign(ray->slope.y);
			if (!is_in_bounds(&position, &game->map)
				|| is_character(&position, &game->map, ID_WALL))
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
