/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:24:20 by brappo            #+#    #+#             */
/*   Updated: 2024/06/22 16:13:32 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

size_t	count_doors(t_map *map)
{
	size_t	y;
	size_t	x;
	size_t	doors_count;

	y = 0;
	doors_count = 0;
	while (y < map->lines_count)
	{
		x = 0 ;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_DOOR_CLOSED)
				doors_count++;
			x++;
		}
		y++;
	}
	return (doors_count);
}

void	find_doors(t_map *map, size_t door_count, t_door *doors)
{
	size_t		y;
	size_t		x;
	size_t		door_index;

	y = 0;
	door_index = 0;
	while (y < map->lines_count)
	{
		x = 0;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_DOOR_CLOSED)
			{
				doors[door_index].position = (t_mlx_coords){x, y};
				doors[door_index].state = CLOSED;
				doors[door_index].transition = 1;
				door_index++;
				if (door_index == door_count)
					return ;
			}
			x++;
		}
		y++;
	}
}

t_door	*find_door_at_position(t_mlx_coords *position, t_door *doors,
	size_t doors_count)
{
	size_t	index;

	index = 0;
	while (index < doors_count)
	{
		if (position->x == doors[index].position.x
			&& position->y == doors[index].position.y)
			return (doors + index);
		index++;
	}
	return (NULL);
}

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

void	update_door(t_door *door, float delta_time, t_map *map)
{
	if (door->state == CLOSING)
	{
		door->transition += delta_time * DOOR_SPEED;
		if (door->transition >= 1)
		{
			door->transition = 1;
			door->state = CLOSED;
		}
	}
	else if (door->state == OPENING)
	{
		door->transition -= delta_time * DOOR_SPEED;
		if (door->transition <= 0)
		{
			door->transition = 0;
			door->state = OPENED;
			map->tiles[door->position.y][door->position.x] = ID_DOOR_OPENED;
		}
	}
}
