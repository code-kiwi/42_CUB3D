/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:01:34 by root              #+#    #+#             */
/*   Updated: 2024/06/22 17:52:35 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "vector_bonus.h"
#include "map_bonus.h"
typedef struct s_raycast	t_raycast;

struct s_raycast
{
	float	unit_length;
	float	sum_length;
	int		sign;
	float	*position;
	bool	is_vertical;
};

static void	calculate_unit_length(t_raycast *ray_x, t_raycast *ray_y,
	t_vector *slope)
{
	ray_x->unit_length = sqrt(1 + pow((slope->y / slope->x), 2));
	ray_y->unit_length = sqrt(1 + pow((slope->x / slope->y), 2));
}

static void	calculate_inital_sum(t_raycast *ray_x, t_raycast *ray_y,
	t_vector *slope, t_vector *position)
{
	if (slope->x < 0)
		ray_x->sum_length = modff(position->x, ray_x->position);
	else
		ray_x->sum_length = 1 - modff(position->x, ray_x->position);
	if (slope->y < 0)
		ray_y->sum_length = 1 - modff(position->y, ray_y->position);
	else
		ray_y->sum_length = modff(position->y, ray_y->position);
	ray_x->sum_length *= ray_x->unit_length;
	ray_y->sum_length *= ray_y->unit_length;
}

static bool	check_door(t_vector *pos, t_game *game, t_ray *ray,
	float length, bool is_vertical)
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

float	raycast_progress(t_raycast *raycast, t_game *game, t_vector *position,
	t_ray *ray)
{
	raycast->position += raycast->sign;
	if (!is_in_bounds(position, &game->map)
		|| is_character(position, &game->map, ID_WALL))
	{
		ray->is_vertical = true;
		return (raycast->sum_length);
	}
	if (check_door(position, game, ray,
			raycast->sum_length + raycast->unit_length / 2, true))
	{
		ray->is_vertical = true;
		ray->is_door = true;
		return (raycast->sum_length + raycast->unit_length / 2);
	}
	raycast->sum_length += raycast->unit_length;
	return (-1);
}

float	raycast(t_vector position, t_game *game, t_ray *ray)
{
	t_raycast	ray_x;
	t_raycast	ray_y;
	float		length;

	ray_x.sign = sign(ray->slope.x);
	ray_y.sign = -sign(ray->slope.y);
	ray_x.is_vertical = true;
	ray_y.is_vertical = false;
	ray_x.position = &position.x;
	ray_y.position = &position.y;
	calculate_unit_length(&ray_x, &ray_y, &ray->slope);
	calculate_inital_sum(&ray_x, &ray_y, &ray->slope, &position);
	while (ray_x.sum_length < MAX_DISTANCE || ray_y.sum_length < MAX_DISTANCE)
	{
		if (ray_x.sum_length <= ray_y.sum_length)
			length = raycast_progress(&ray_x, game, &position, ray);
		else
			length = raycast_progress(&ray_y, game, &position, ray);
		if (length != -1)
			return (length);
	}
	return (MAX_DISTANCE);
}
