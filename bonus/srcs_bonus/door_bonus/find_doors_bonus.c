/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:24:20 by brappo            #+#    #+#             */
/*   Updated: 2024/06/24 09:18:16 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "door_bonus.h"

t_door	*find_door_at_position(t_mlx_coords *position, t_game *game)
{
	size_t	index;

	index = 0;
	if (game->last_door_seen != NULL
		&& game->last_door_seen->position.x == position->x
		&& game->last_door_seen->position.y == position->y)
		return (game->last_door_seen);
	while (index < game->door_count)
	{
		if (position->x == game->doors[index].position.x
			&& position->y == game->doors[index].position.y)
		{
			game->last_door_seen = game->doors + index;
			return (game->doors + index);
		}
		index++;
	}
	return (NULL);
}
