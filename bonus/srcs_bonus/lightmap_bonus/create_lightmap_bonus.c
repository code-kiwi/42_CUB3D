/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lightmap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:15:24 by brappo            #+#    #+#             */
/*   Updated: 2024/09/11 06:12:22 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "lightmap_bonus.h"

static bool	alloc_lightmap(t_map *map)
{
	size_t	lines_count;
	size_t	line_length;
	size_t	index;

	lines_count = map->lines_count * LIGHTMAP_TILE_RATIO;
	map->lightmap = ft_calloc(lines_count, sizeof(float *));
	if (map->lightmap == NULL)
		return (false);
	index = 0;
	while (index < lines_count)
	{
		line_length = map->lines_lengths[(int)(index / LIGHTMAP_TILE_RATIO)];
		line_length *= LIGHTMAP_TILE_RATIO;
		map->lightmap[index] = ft_calloc(line_length, sizeof(float));
		if (map->lightmap[index] == NULL)
		{
			free_array((char **)map->lightmap, index, true);
			return (false);
		}
		index++;
	}
	return (true);
}

#include <stdio.h>

static void	print_lightmap(t_map *map)
{
	size_t	y;
	size_t	x;
	size_t	line_length;
	size_t	lines_count;

	y = 0;
	lines_count = map->lines_count * LIGHTMAP_TILE_RATIO;
	while (y < lines_count)
	{
		x = 0;
		line_length = map->lines_lengths[(int)(y / LIGHTMAP_TILE_RATIO)];
		line_length *= LIGHTMAP_TILE_RATIO;
		while (x < line_length)
		{
			printf("%d,", (int)(map->lightmap[y][x]));
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

bool	create_lightmap(t_map *map, t_game *game)
{
	t_vector	*lights_pos;
	size_t		lights_count;

	if (map == NULL || game == NULL)
		return (false);
	if (!alloc_lightmap(map))
		return (false);
	lights_count = count_lights(map);
	if (lights_count == 0)
		return (true);
	lights_pos = get_lights_position(map, lights_count);
	if (lights_pos == NULL)
		return (false);
	set_lightmap_values(map, lights_pos, lights_count);
	print_lightmap(map);
	free(lights_pos);
	return (true);
}
