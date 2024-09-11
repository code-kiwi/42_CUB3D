/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_luminosity_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:27:48 by brappo            #+#    #+#             */
/*   Updated: 2024/09/11 09:47:49 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"
#include "lightmap_bonus.h"
#include "mlx_api_bonus.h"

#include <stdio.h>

float	get_luminosity(t_vector *position, float **lightmap)
{
	t_mlx_coords	lightmap_coords;

	if (position->x < 0 || position->y < 0)
		return (0.0f);
	lightmap_coords.x = position->x * LIGHTMAP_TILE_RATIO;
	lightmap_coords.y = position->y * LIGHTMAP_TILE_RATIO;
	return (lightmap[lightmap_coords.y][lightmap_coords.x]);
}