/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:42:52 by brappo            #+#    #+#             */
/*   Updated: 2024/06/13 15:38:03 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

bool	check_surrounding_tile(t_map *map, size_t x, size_t y)
{
	if (map->tiles[y][x] != ' ')
		return (true);
	if (x > 0 && map->tiles[y][x - 1] != '1'
		&& map->tiles[y][x - 1] != ' ')
		return (false);
	if (y > 0 && map->tiles[y - 1][x] != '1'
		&& map->tiles[y - 1][x] != ' ')
		return (false);
	if (x < map->lines_lengths[y] - 1 && map->tiles[y][x + 1] != '1'
		&& map->tiles[y][x + 1] != ' ')
		return (false);
	if (y < map->lines_count - 1 && map->tiles[y + 1][x] != '1'
		&& map->tiles[y + 1][x] != ' ')
		return (false);
	return (true);
}

bool	check_map_edge(t_map *map)
{
	size_t	index;

	if (ft_strchr(map->tiles[0], '0')
		|| ft_strchr(map->tiles[map->lines_count - 1], '0'))
		return (false);
	index = 0;
	while (index < map->lines_count)
	{
		if (map->tiles[index][0] == '0'
			|| map->tiles[index][map->lines_lengths[index] - 1] == '0')
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
	{
		write(STDOUT_FILENO, "invalid map\n", 12);
		return (false);
	}
	while (y < map->lines_count)
	{
		x = 0;
		while (x < map->lines_lengths[y])
		{
			if (!ft_strchr(" 01NSEW\n", map->tiles[y][x])
				|| !check_surrounding_tile(map, x, y))
			{
				write(STDOUT_FILENO, "invalid map\n", 12);
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
