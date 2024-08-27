/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:24:20 by brappo            #+#    #+#             */
/*   Updated: 2024/08/27 13:48:22 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"

t_door	*find_door_at_position(t_mlx_coords *position, t_game *game)
{
	size_t	index;
	t_door	*last_door_seen;

	index = 0;
	last_door_seen = game->player.last_door_seen;
	if (last_door_seen != NULL
		&& last_door_seen->position.x == position->x
		&& last_door_seen->position.y == position->y)
		return (last_door_seen);
	while (index < game->door_count)
	{
		if (position->x == game->doors[index].position.x
			&& position->y == game->doors[index].position.y)
		{
			last_door_seen = game->doors + index;
			return (game->doors + index);
		}
		index++;
	}
	return (NULL);
}
