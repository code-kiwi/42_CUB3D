/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:54:08 by root              #+#    #+#             */
/*   Updated: 2024/06/23 16:47:09 by root             ###   ########.fr       */
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
		map->tiles[door->position.y][door->position.x] = ID_DOOR_CLOSED;
		door->state = CLOSING;
	}
}
