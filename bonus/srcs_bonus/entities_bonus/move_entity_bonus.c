/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_entity_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:22:48 by brappo            #+#    #+#             */
/*   Updated: 2024/08/26 17:47:41 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	tile_pos.x = position->x;
	tile_pos.y = position->y;
	if (!is_walkable(map, &tile_pos)
		|| collide_entity(entities, position))
	{
		position->x = save.x;
		position->y = save.y;
		return (false);
	}
	return (true);
}
