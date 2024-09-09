/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lightmap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 05:42:05 by brappo            #+#    #+#             */
/*   Updated: 2024/09/09 13:15:12 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "lightmaps_bonus.h"

static float	**alloc_lightmap(t_map *map)
{
	float	**lightmap;
	size_t	index;
	size_t	line_length;
	size_t	lines_count;

	lines_count = map->lines_count * LIGHTMAP_TILE_RATIO;
	lightmap = ft_calloc(lines_count, sizeof(float *));
	if (lightmap == NULL)
		return (NULL);
	index = 0;
	while (index < lines_count)
	{
		line_length = map->lines_lengths[(int)(index / LIGHTMAP_TILE_RATIO)];
		line_length *= LIGHTMAP_TILE_RATIO;
		lightmap[index] = ft_calloc(line_length, sizeof(float));
		if (lightmap[index] == NULL)
		{
			free_array((char **)lightmap, lines_count, true);
			return (NULL);
		}
		index++;
	}
	return (lightmap);
}

bool	create_lightmap(t_map *map, t_game *game)
{
	size_t	x;
	size_t	y;

	if (map == NULL || game == NULL)
		return (false);
	map->lightmap = alloc_lightmap(map);
	if (map->lightmap == NULL)
		return (false);
	y = 0;
	while (y < map->lines_count)
	{
		x = 0;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_MAP_LIGHT)
				calculate_lightning(map->lightmap, x, y, game);
			x++;
		}
		y++;
	}
	return (true);
}
