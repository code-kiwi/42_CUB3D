/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:18:21 by brappo            #+#    #+#             */
/*   Updated: 2024/06/24 09:21:13 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "door_bonus.h"
#include "libft.h"

static size_t	count_doors(t_map *map)
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

bool	init_doors(t_game *game)
{
	game->door_count = count_doors(&game->map);
	if (game->door_count != 0)
	{
		game->doors = ft_calloc(game->door_count, sizeof(t_door));
		if (game->doors == NULL)
			return (false);
		find_doors(&game->map, game->door_count, game->doors);
	}
	else
		game->doors = NULL;
	game->last_door_seen = NULL;
	return (true);
}