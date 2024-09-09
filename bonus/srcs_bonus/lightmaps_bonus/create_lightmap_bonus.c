/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lightmap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 05:42:05 by brappo            #+#    #+#             */
/*   Updated: 2024/09/09 06:20:03 by brappo           ###   ########.fr       */
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

static void	calculate_lightning(char **lightmap, size_t i, size_t j)
{
	float		angle;
	float		angle_unit;
	t_vector	ray_slope;
	float		distance;

	i *= LIGHTMAP_TILE_RATIO + LIGHTMAP_TILE_RATIO / 2;
	j *= LIGHTMAP_TILE_RATIO + LIGHTMAP_TILE_RATIO / 2;
	angle = 0;
	angle_unit = 2 * PI / 360;
	while (angle < 2 * PI)
	{
		t_vector_get_slope(&ray_slope, angle);
		angle += angle_unit;
		angle++;
	}
}

char	**create_lightmap(t_map *map)
{
	char	**lightmap;
	size_t	i;
	size_t	j;

	if (map == NULL)
		return (NULL);
	lightmap = alloc_lightmap(map);
	if (lightmap == NULL)
		return (NULL);
	i = 0;
	while (i < map->lines_count)
	{
		j = 0;
		while (j < map->lines_lengths[i])
		{
			if (map->tiles[j][i] == ID_MAP_LIGHT)
				calculate_lightning(lightmap, i, j);
			j++;
		}
		i++;
	}
	return (lightmap);
}
