/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:43:55 by brappo            #+#    #+#             */
/*   Updated: 2024/06/12 12:39:52 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_in_bounds(t_vector *position, t_map *map)
{
	if (position->x < 0
		|| position->y < 0
		|| position->x > map->length_x
		|| position->y > map->length_y)
		return (false);
	return (true);
}
