/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:59:07 by brappo            #+#    #+#             */
/*   Updated: 2024/06/12 11:55:19 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

t_vector	calculate_unit_length(t_vector *slope)
{
	t_vector	unit_length;

	unit_length.x = sqrt(1 + pow((slope->y / slope->x), 2));
	unit_length.y = sqrt(1 + pow((slope->x / slope->y), 2));
	return (unit_length);
}

t_vector	raycast(t_vector position, t_vector *slope, t_map *map)
{
	t_vector	unit_length;
	t_vector	sum_length;

	unit_length = calculate_unit_length(slope);
	copy(&sum_length, &unit_length);
	while (true)
	{
		if (sum_length.x <= sum_length.y)
		{
			position.x -= sign(slope->x);
			sum_length.x += unit_length.x;
		}
		else
		{
			position.y = sign(slope->y);
			sum_length.y += unit_length.y;
		}
		if (!is_in_bounds(&position, map))
			return (vector_error());
		if (map->tiles[(int)floorf(position.y)][(int)floorf(position.x)] == '1')
			return (position);
	}
	return (vector_error());
}

