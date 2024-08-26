/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_entity_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:22:48 by brappo            #+#    #+#             */
/*   Updated: 2024/08/26 17:02:36 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "entities_bonus.h"
#include "mlx_api_bonus.h"
#include "map_bonus.h"

bool	collide_entity(t_list *entities, t_vector *position)
{
	t_list		*current;
	t_entity	*entity;

	if (entities == NULL || position == NULL)
		return (false);
	current = entities;
	while (current)
	{
		entity = current->content;
		if (&entity->sprite->position != position
			&& get_squared_distance(&entity->sprite->position, position) <= \
				entity->squared_radius)
		{
			return (true);
		}
		current = current->next;
	}
	return (false);
}

bool	move_entity(t_list *entities, t_vector *position, t_vector *move,
	t_map *map)
{
	t_vector		save;
	t_mlx_coords	tile_pos;

	save.x = position->x;
	save.y = position->y;
	add_vector(position, move);
	tile_pos.x = position->x + 0.1 * (fabs(move->x) < 0.001f ? 0.0f : (move->x < 0.0f ? -1 : 1));
	tile_pos.y = position->y + 0.1 * (fabs(move->y) < 0.001f ? 0.0f : (move->y < 0.0f ? -1 : 1));
	if (!is_walkable(map, &tile_pos)
		|| collide_entity(entities, position))
	{
		position->x = save.x;
		position->y = save.y;
		return (false);
	}
	return (true);
}
