/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:42:52 by brappo            #+#    #+#             */
/*   Updated: 2024/06/17 15:16:23 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"
#include "libft.h"

static bool	check_surrounding_tile(t_map *map, size_t x, size_t y)
{
	t_vector	coords;

	if (map->tiles[y][x] == ID_WALL || map->tiles[y][x])
		return (true);
	coords.y = y;
	coords.x = x - 1;
	if (!is_in_bounds(&coords, map)
		|| map->tiles[y][x - 1] == ID_SPACE)
		return (false);
	coords.x = x + 1;
	if (!is_in_bounds(&coords, map)
		|| map->tiles[y][x + 1] == ID_SPACE)
		return (false);
	coords.x = x;
	coords.y = y - 1;
	if (!is_in_bounds(&coords, map)
		|| map->tiles[y - 1][x] == ID_SPACE)
		return (false);
	coords.y = y + 1;
	if (!is_in_bounds(&coords, map)
		|| map->tiles[y + 1][x] == ID_SPACE)
		return (false);
	return (true);
}

bool	is_map_valid(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->lines_count)
	{
		x = 0;
		if (map->tiles[y][0] == '\n')
			return (error_print(ERR_EMPTY_LINE), false);
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
