/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lights_position_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:18:21 by brappo            #+#    #+#             */
/*   Updated: 2024/09/12 06:06:58 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"
#include "vector_bonus.h"
#include "libft.h"

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

static void	find_lights(t_map *map, size_t light_count, t_vector *lights_pos)
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
				lights_pos[light_index].x = (float)x + 0.5f;
				lights_pos[light_index].y = (float)y + 0.5f;
				light_index++;
				if (light_index == light_count)
					return ;
			}
			x++;
		}
		y++;
	}
}

t_vector	*get_lights_position(t_map *map, size_t light_count)
{
	t_vector	*lights_pos;

	if (map == NULL || light_count == 0)
		return (NULL);
	lights_pos = ft_calloc(light_count, sizeof(t_vector));
	if (lights_pos == NULL)
		return (NULL);
	find_lights(map, light_count, lights_pos);
	return (lights_pos);
}
