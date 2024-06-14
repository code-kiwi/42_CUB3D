/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_bounds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:54:27 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/14 11:37:41 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

#include "cub3d.h"
#include "map.h"
#include "vector.h"

bool	is_in_bounds(t_vector *position, t_map *map)
{
	if (position->x < 0
		|| position->y < 0
		|| position->x > map->lines_lengths[(int)floorf(position->y)]
		|| position->y > map->lines_count)
		return (false);
	return (true);
}

bool	is_wall(t_vector *position, t_map *map)
{
	int	tile_x;
	int	tile_y;

	tile_x = floorf(position->x);
	tile_y = floorf(position->y);
	return (map->tiles[tile_y][tile_x] == ID_WALL);
}