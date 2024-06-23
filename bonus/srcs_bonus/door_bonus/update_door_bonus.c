/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_door_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:54:13 by root              #+#    #+#             */
/*   Updated: 2024/06/23 16:57:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "door_bonus.h"

static void	close_door(t_door *door, float delta_time)
{
	door->transition += delta_time * DOOR_SPEED;
	if (door->transition >= 1)
	{
		door->transition = 1;
		door->state = CLOSED;
	}
}

static void	open_door(t_door *door, float delta_time, t_map *map)
{
	door->transition -= delta_time * DOOR_SPEED;
	if (door->transition <= 0)
	{
		door->transition = 0;
		door->state = OPENED;
		door->time_since_opened = 0;
		map->tiles[door->position.y][door->position.x] = ID_DOOR_OPENED;
	}
}

static void	update_door(t_door *door, float delta_time, t_map *map,
	t_vector *player_pos)
{
	if (door->state == OPENED)
	{
		door->time_since_opened += delta_time;
		if (door->time_since_opened > DOOR_TIME_TO_CLOSE
			&& !((int)player_pos->x == door->position.x)
			&& (int)player_pos->y == door->position.y)
		{
			door->state = CLOSING;
			map->tiles[door->position.y][door->position.x] = ID_DOOR_CLOSED;
		}
	}
	else if (door->state == CLOSING)
		close_door(door, delta_time);
	else if (door->state == OPENING)
		open_door(door, delta_time, map);
}

void	update_doors(t_game *game, float delta_time)
{
	size_t		index;

	index = 0;
	while (index < game->door_count)
	{
		update_door(&game->doors[index], delta_time, &game->map,
			&game->player.position);
		index++;
	}
}
