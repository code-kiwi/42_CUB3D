/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:54:08 by root              #+#    #+#             */
/*   Updated: 2024/06/29 13:55:07 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "door_bonus.h"

void	open_looked_door(t_ray *look_ray, t_map *map)
{
	t_door	*door;

	if (!look_ray->is_door)
		return ;
	if (look_ray->length > PLAYER_INTERACTION_DISTANCE)
		return ;
	door = look_ray->door;
	if (door->state == CLOSED)
		door->state = OPENING;
	else if (door->state == OPENED)
	{
		map->tiles[door->position.y][door->position.x] = ID_MAP_DOOR_CLOSED;
		door->state = CLOSING;
	}
}
