/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bullet_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:58:30 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/31 19:54:41 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "bullets_bonus.h"
#include "sprite_bonus.h"
#include "entities_bonus.h"

static t_entity	*bullet_collide_entity(t_list *entities, t_vector *position)
{
	t_list		*current;
	t_entity	*entity;

	if (entities == NULL || position == NULL)
		return (false);
	current = entities;
	while (current)
	{
		entity = current->content;
		if (get_squared_distance(&entity->sprite->position, position) <= \
			entity->bullet_sensibility_radius)
			return (entity);
		current = current->next;
	}
	return (NULL);
}

bool	move_bullet(
	t_list *entities,
	t_bullet *bullet,
	t_vector *move,
	t_map *map
)
{
	t_vector		save;
	t_mlx_coords	tile_pos;
	t_vector		*position;
	t_entity		*collided_entity;

	if (entities == NULL || bullet == NULL || move == NULL || map == NULL)
		return (false);
	position = &bullet->sprite->position;
	save.x = position->x;
	save.y = position->y;
	add_vector(position, move);
	tile_pos.x = position->x;
	tile_pos.y = position->y;
	collided_entity = bullet_collide_entity(entities, position);
	if (!is_walkable(map, &tile_pos) || collided_entity != NULL)
	{
		if (collided_entity != NULL)
			bullet->collided_entity = collided_entity;
		position->x = save.x;
		position->y = save.y;
		return (false);
	}
	return (true);
}
