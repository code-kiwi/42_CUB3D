/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lightmap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 05:42:05 by brappo            #+#    #+#             */
/*   Updated: 2024/09/09 06:30:13 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "lightmaps_bonus.h"

static char	**alloc_lightmap(t_map *map)
{
	char	**lightmap;
	size_t	index;
	size_t	line_length;
	size_t	lines_count;

	lines_count = map->lines_count * LIGHTMAP_TILE_RATIO;
	lightmap = ft_calloc(lines_count, sizeof(char *));
	if (lightmap == NULL)
		return (NULL);
	index = 0;
	while (index < lines_count)
	{
		line_length = map->lines_lengths[(int)(index / LIGHTMAP_TILE_RATIO)];
		line_length *= LIGHTMAP_TILE_RATIO;
		lightmap[index] = ft_calloc(line_length, sizeof(char));
		if (lightmap[index] == NULL)
		{
			ft_free_str_array(&lightmap);
			return (NULL);
		}
		index++;
	}
	return (lightmap);
}

char	**create_lightmap(t_map *map, t_game *game)
{
	char	**lightmap;
	size_t	x;
	size_t	y;

	if (map == NULL)
		return (NULL);
	lightmap = alloc_lightmap(map);
	if (lightmap == NULL)
		return (NULL);
	y = 0;
	while (y < map->lines_count)
	{
		x = 0;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_MAP_LIGHT)
				calculate_lightning(lightmap, x, y, game);
			x++;
		}
		y++;
	}
	return (lightmap);
}
