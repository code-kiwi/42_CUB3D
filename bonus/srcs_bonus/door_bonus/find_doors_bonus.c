/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:24:20 by brappo            #+#    #+#             */
/*   Updated: 2024/06/23 16:46:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "door_bonus.h"

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
				doors[door_index].time_since_opened = 0;
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
