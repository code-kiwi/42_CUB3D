/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_bounds_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:54:27 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/19 11:07:32 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

#include "cub3d_bonus.h"
#include "map_bonus.h"
#include "vector_bonus.h"

bool	is_in_bounds(t_vector *position, t_map *map)
{
	if (position->x < 0
		|| position->y < 0
		|| position->y >= map->lines_count
		|| position->x >= map->lines_lengths[(int)floorf(position->y)])
		return (false);
	return (true);
}

bool	is_wall(t_vector *position, t_map *map)
{
	int	tile_x;
	int	tile_y;

	if (!is_in_bounds(position, map))
		return (true);
	tile_x = position->x;
	tile_y = position->y;
	return (map->tiles[tile_y][tile_x] == ID_WALL);
}
