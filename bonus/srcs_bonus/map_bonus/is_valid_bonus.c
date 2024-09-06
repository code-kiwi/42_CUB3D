/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:42:52 by brappo            #+#    #+#             */
/*   Updated: 2024/09/06 09:18:29 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

static bool	is_space(t_vector *coords, t_map *map)
{
	int	x;
	int	y;

	x = coords->x;
	y = coords->y;
	return (!is_in_bounds(coords, map) || map->tiles[y][x] == ID_MAP_SPACE);
}

static bool	check_surrounding_tile(t_map *map, int x, int y)
{
	t_vector	coords;

	if (map->tiles[y][x] == ID_MAP_WALL || map->tiles[y][x] == ID_MAP_SPACE)
		return (true);
	coords.y = y;
	coords.x = x - 1;
	if (is_space(&coords, map))
		return (false);
	coords.x = x + 1;
	if (is_space(&coords, map))
		return (false);
	coords.x = x;
	coords.y = y - 1;
	if (is_space(&coords, map))
		return (false);
	coords.y = y + 1;
	if (is_space(&coords, map))
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
		while (x < map->lines_lengths[y])
		{
			if (!ft_strchr(MAP_ALLOWED_CHARS, map->tiles[y][x]))
			{
				ft_dprintf(STDERR_FILENO, ERR_ELEM, map->tiles[y][x]);
				return (false);
			}
			if (!check_surrounding_tile(map, x, y))
				return (error_print(ERR_WALLS), false);
			x++;
		}
		y++;
	}
	return (true);
}
