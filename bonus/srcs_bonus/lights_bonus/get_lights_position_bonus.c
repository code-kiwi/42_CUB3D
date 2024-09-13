/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lights_position_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:18:21 by brappo            #+#    #+#             */
/*   Updated: 2024/09/13 03:55:37 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"
#include "vector_bonus.h"
#include "libft.h"
#include "lights_bonus.h"

size_t	count_lights(t_map *map)
{
	size_t	y;
	size_t	x;
	size_t	lights_count;

	y = 0;
	lights_count = 0;
	while (y < map->lines_count)
	{
		x = 0 ;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_MAP_LIGHT
				|| map->tiles[y][x] == ID_MAP_LIGHT - 32)
			{
				lights_count++;
			}
			x++;
		}
		y++;
	}
	return (lights_count);
}

static void	find_lights(t_map *map, size_t light_count, t_light *lights)
{
	size_t		y;
	size_t		x;
	size_t		light_index;

	y = 0;
	light_index = 0;
	while (y < map->lines_count)
	{
		x = 0;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_MAP_LIGHT
				|| map->tiles[y][x] == ID_MAP_LIGHT - 32)
			{
				lights[light_index].position.y = (float)y + 0.5f;
				lights[light_index].position.x = (float)x + 0.5f;
				light_index++;
				if (light_index == light_count)
					return ;
			}
			x++;
		}
		y++;
	}
}

bool	get_lights_position(t_map *map)
{
	if (map == NULL)
		return (false);
	if (map->lights_count == 0)
		return (true);
	map->lights = ft_calloc(map->lights_count, sizeof(t_light));
	if (map->lights == NULL)
		return (false);
	find_lights(map, map->lights_count, map->lights);
	return (true);
}
