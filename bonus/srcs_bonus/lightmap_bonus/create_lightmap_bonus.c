/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lightmap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:15:24 by brappo            #+#    #+#             */
/*   Updated: 2024/09/11 05:10:31 by brappo           ###   ########.fr       */
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

bool	create_lightmap(t_map *map, t_game *game)
{
	t_vector	*lights_pos;
	size_t		lights_count;

	if (map == NULL || game == NULL)
		return (false);
	if (!alloc_lightmap(map))
		return (false);
	lights_count  = count_lights(map);
	if (lights_count == 0)
		return (true);
	lights_pos = get_lights_position(map, lights_count);
	if (lights_pos == NULL)
	free(lights_pos);
	return (true);
}
