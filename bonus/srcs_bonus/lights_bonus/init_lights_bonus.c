/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lights_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:15:24 by brappo            #+#    #+#             */
/*   Updated: 2024/09/13 03:04:49 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "lights_bonus.h"

bool	init_lights(t_game *game)
{
	t_vector	*lights_pos;
	size_t		lights_count;
	t_map		*map;

	if (game == NULL || game->map == NULL)
		return (false);
	map = game->map;
	lights_count = count_lights(map);
	if (lights_count == 0)
		return (true);
	lights_pos = get_lights_position(map, lights_count);
	if (lights_pos == NULL)
		return (false);
	free(lights_pos);
	return (true);
}
