/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_door_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:01:43 by root              #+#    #+#             */
/*   Updated: 2024/06/23 16:46:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "door_bonus.h"

bool	is_door(t_vector *pos, t_game *game, t_ray *ray,
	t_raycast *raycast)
{
	t_vector		point_pos;
	t_mlx_coords	map_pos;
	t_door			*door;
	float			length;

	if (!is_character(pos, &game->map, ID_DOOR_CLOSED)
		&& !is_character(pos, &game->map, ID_DOOR_OPENED))
		return (false);
	length = raycast->sum_length + raycast->unit_length / 2;
	point_pos.x = game->player.position.x + ray->slope.x * length;
	point_pos.y = game->player.position.y - ray->slope.y * length;
	map_pos.x = point_pos.x;
	map_pos.y = point_pos.y;
	if (map_pos.x != pos->x || map_pos.y != pos->y)
		return (false);
	door = find_door_at_position(&map_pos, game->doors, game->door_count);
	if (door == NULL)
		return (false);
	if ((raycast->is_vertical && point_pos.y - (int)point_pos.y < door->transition)
		|| (!raycast->is_vertical && point_pos.x - (int)point_pos.x < door->transition))
	{
		ray->door = door;
		return (true);
	}
	return (false);
}
