/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entities_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:01:50 by brappo            #+#    #+#             */
/*   Updated: 2024/07/17 10:08:16 by root             ###   ########.fr       */
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
	new_entity->is_path_circular = false;
	new_entity->path = NULL;
	new_entity->sprite->frame_update_delta = 0;
	new_entity->cooldown = 0;
}

static void	*add_entity(t_game *game, float x, float y, char id)
{
	t_list		*new_node;
	t_entity	*new_entity;
	t_sprite	*new_sprite;

	new_sprite = add_sprite(game, x, y, id);
	if (new_sprite == NULL)
		return (NULL);
	new_entity = ft_calloc(1, sizeof(t_entity));
	if (new_entity == NULL)
		return (NULL);
	init_entity(new_entity, new_sprite, x, y);
	if (!init_entity_type(new_entity, id, game->textures))
		return (free(new_entity), NULL);
	new_node = ft_lstnew(new_entity);
	if (new_node == NULL)
		return (t_entity_destroy(new_entity), NULL);
	ft_lstadd_front(&game->entities, new_node);
	return (new_entity);
}

bool	init_entities(t_game *game)
{
	t_list		*current;
	t_entity	*entity;
	t_list		*new_sprite_node;

	if (!get_elem_into_list(game, &game->entities, IDS_MAP_ENTITY, \
			add_entity))
		return (false);
	game->last_entity_updated = game->entities;
	return (true);
}
