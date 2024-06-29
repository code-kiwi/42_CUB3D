/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entities_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:01:50 by brappo            #+#    #+#             */
/*   Updated: 2024/06/29 14:34:10 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "map_bonus.h"
#include "cub3d_bonus.h"
#include "libft.h"

bool	add_entity(t_list **entities, float x, float y)
{
	t_list		*new_node;
	t_entity	*new_entity;

	new_entity = ft_calloc(1, sizeof(t_entity));
	if (new_entity == NULL)
		return (false);
	new_entity->sprite.position.x = x;
	new_entity->sprite.position.y = y;
	new_node = ft_lstnew(new_entity);
	if (new_node == NULL)
	{
		free(new_entity);
		return (false);
	}
	ft_lstadd_front(entities, new_node);
	return (true);
}

void	t_entity_init(t_entity *entity, t_list *animation)
{
	if (entity == NULL)
		return ;
	t_sprite_init(&entity->sprite, animation);
	entity->is_path_circular = false;
	entity->path = NULL;
	entity->speed = ENTITY_SPEED;
}

bool	init_entities(t_game *game)
{
	t_list		*current;
	t_entity	*entity;

	if (!get_elemn_into_list(&game->map, &game->entities, ID_MAP_ENTITY, \
			add_entity))
		return (false);
	current = game->entities;
	while (current)
	{
		entity = current->content;
		t_entity_init(entity, game->textures[7]);
		current = current->next;
	}
	return (true);
}
