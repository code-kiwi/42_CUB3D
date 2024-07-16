/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entities_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:01:50 by brappo            #+#    #+#             */
/*   Updated: 2024/07/16 10:32:23 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "map_bonus.h"
#include "cub3d_bonus.h"
#include "libft.h"

static void	init_entity(t_entity *new_entity, t_sprite *new_sprite, float x,
	float y)
{
	new_entity->sprite = new_sprite;
	new_entity->sprite->position.x = x;
	new_entity->sprite->position.y = y;
	new_entity->squared_radius = ENTITY_RADIUS * ENTITY_RADIUS;
	new_entity->health_point = ENTITY_HEALTH_POINT;
	new_entity->is_path_circular = false;
	new_entity->path = NULL;
	new_entity->speed = ENTITY_SPEED;
}

static bool	add_entity(t_game *game, float x, float y, char id)
{
	t_list		*new_node;
	t_entity	*new_entity;
	t_sprite	*new_sprite;

	new_sprite = ft_calloc(1, sizeof(t_sprite));
	if (new_sprite == NULL)
		return (false);
	new_entity = ft_calloc(1, sizeof(t_entity));
	if (new_entity == NULL)
		return (free(new_sprite), false);
	init_entity(new_entity, new_sprite, x, y);
	if (!init_entity_type(new_entity, id, game->textures))
	{
		free(new_sprite);
		return (free(new_entity), false);
	}
	new_node = ft_lstnew(new_entity);
	if (new_node == NULL)
	{
		free(new_sprite);
		return (t_entity_destroy(new_entity), false);
	}
	ft_lstadd_front(&game->entities, new_node);
	return (true);
}

bool	init_entities(t_game *game)
{
	t_list		*current;
	t_entity	*entity;
	t_list		*new_sprite_node;

	if (!get_elem_into_list(game, &game->entities, IDS_MAP_ENTITY, \
			add_entity))
		return (false);
	current = game->entities;
	while (current)
	{
		entity = current->content;
		new_sprite_node = ft_lstnew(entity->sprite);
		if (new_sprite_node == NULL)
			return (false);
		ft_lstadd_front(&game->sprites, new_sprite_node);
		current = current->next;
	}
	game->last_entity_updated = game->entities;
	return (true);
}
