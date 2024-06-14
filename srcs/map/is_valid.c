/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:42:52 by brappo            #+#    #+#             */
/*   Updated: 2024/06/14 12:32:38 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"
#include "libft.h"

static bool	check_surrounding_tile(t_map *map, size_t x, size_t y)
{
	if (map->tiles[y][x] != ID_SPACE)
		return (true);
	if (x > 0 && map->tiles[y][x - 1] != ID_WALL
		&& map->tiles[y][x - 1] != ID_SPACE)
		return (false);
	if (y > 0 && map->tiles[y - 1][x] != ID_WALL
		&& map->tiles[y - 1][x] != ID_SPACE)
		return (false);
	if (x < map->lines_lengths[y] - 1 && map->tiles[y][x + 1] != ID_WALL
		&& map->tiles[y][x + 1] != ID_SPACE)
		return (false);
	if (y < map->lines_count - 1 && map->tiles[y + 1][x] != ID_WALL
		&& map->tiles[y + 1][x] != ID_SPACE)
		return (false);
	return (true);
}

static bool	check_map_edge(t_map *map)
{
	size_t	index;

	if (ft_strchr(map->tiles[0], ID_TILE)
		|| ft_strchr(map->tiles[map->lines_count - 1], ID_TILE))
		return (false);
	index = 0;
	while (index < map->lines_count)
	{
		if (map->tiles[index][0] == ID_TILE
			|| map->tiles[index][map->lines_lengths[index] - 1] == ID_TILE)
			return (false);
		index++;
	}
	return (true);
}

bool	is_map_valid(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	if (!check_map_edge(map))
		return (error_print(ERR_WALLS), false);
	while (y < map->lines_count)
	{
		x = 0;
		while (x < map->lines_lengths[y])
		{
			if (!ft_strchr(MAP_ALLOWED_CHARS, map->tiles[y][x]))
				return (error_print(ERR_ELEM), false);
			if (!check_surrounding_tile(map, x, y))
				return (error_print(ERR_WALLS), false);
			x++;
		}
		y++;
	}
	return (true);
}
