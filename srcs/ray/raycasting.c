/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:59:07 by brappo            #+#    #+#             */
/*   Updated: 2024/06/14 11:38:21 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"
#include "vector.h"
#include "map.h"

static void	calculate_unit_length(t_vector *unit_length, t_vector *slope)
{
	unit_length->x = sqrt(1 + pow((slope->y / slope->x), 2));
	unit_length->y = sqrt(1 + pow((slope->x / slope->y), 2));
}

static void	calculate_inital_sum(t_vector *sum_length, t_vector *unit_length,
	t_vector *position)
{
	sum_length->x = 1 - modff(position->x, &position->x);
	sum_length->y = 1 - modff(position->y, &position->y);
	sum_length->x *= unit_length->x;
	sum_length->y *= unit_length->y;
}

float	raycast(t_vector position, t_vector *slope, t_map *map)
{
	t_vector	unit_length;
	t_vector	sum_length;

	calculate_unit_length(&unit_length, slope);
	calculate_inital_sum(&sum_length, &unit_length, &position);
	while (true)
	{
		if (sum_length.x <= sum_length.y)
		{
			position.x += sign(slope->x);
			if (is_wall(&position, map))
				return (sum_length.x);
			sum_length.x += unit_length.x;
		}
		else
		{
			position.y -= sign(slope->y);
			if (is_wall(&position, map))
				return (sum_length.y);
			sum_length.y += unit_length.y;
		}
		if (!is_in_bounds(&position, map))
			break ;
	}
	return (-1);
}