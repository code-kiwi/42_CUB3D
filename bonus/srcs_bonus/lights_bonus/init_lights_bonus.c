/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lights_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:15:24 by brappo            #+#    #+#             */
/*   Updated: 2024/09/13 03:52:32 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "lights_bonus.h"

void	free_lights(t_light **lights, size_t lights_count)
{
	size_t	index;

	index = 0;
	while (index < lights_count)
	{
		if ((*lights)[index].rays != NULL)
			free((*lights)[index].rays);
		index++;
	}
	free(*lights);
	*lights = NULL;
}

bool	init_lights(t_game *game)
{
	t_map		*map;

	if (game == NULL || game->map == NULL)
		return (false);
	map = game->map;
	map->lights_count = count_lights(map);
	if (map->lights_count == 0)
		return (true);
	if (!get_lights_position(map))
		return (false);
	if (!set_lights_values(game))
	{
		free_lights(&map->lights, map->lights_count);
		return (false);
	}
	return (true);
}
