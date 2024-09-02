/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:18:21 by brappo            #+#    #+#             */
/*   Updated: 2024/09/02 16:59:46 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"
#include "libft.h"

static bool	is_door_valid(t_map *map, size_t x, size_t y)
{
	if (x == 0 || y == 0)
		return (false);
	if (x == map->lines_lengths[y] - 1 || y == map->lines_count - 1)
		return (false);
	if (map->tiles[y][x - 1] == '1' && map->tiles[y][x + 1] == '1')
		return (true);
	if (map->tiles[y - 1][x] == '1' && map->tiles[y + 1][x] == '1')
		return (true);
	return (false);
}

static ssize_t	count_doors(t_map *map)
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
			if (map->tiles[y][x] == ID_MAP_DOOR_CLOSED)
			{
				if (!is_door_valid(map, x, y))
					return (-1);
				doors_count++;
			}
			x++;
		}
		y++;
	}
	return (doors_count);
}

static void	find_doors(t_map *map, size_t door_count, t_door *doors)
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
			if (map->tiles[y][x] == ID_MAP_DOOR_CLOSED)
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

bool	init_doors(t_game *game)
{
	ssize_t	door_count;

	door_count = count_doors(game->map);
	if (door_count == -1)
	{
		error_print(INVALID_DOOR);
		return (false);
	}
	game->door_count = door_count;
	if (game->door_count != 0)
	{
		game->doors = ft_calloc(game->door_count, sizeof(t_door));
		if (game->doors == NULL)
			return (false);
		find_doors(game->map, game->door_count, game->doors);
	}
	else
		game->doors = NULL;
	game->player.last_door_seen = NULL;
	return (true);
}
