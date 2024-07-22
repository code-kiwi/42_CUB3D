/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pain_elem_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:59 by brappo            #+#    #+#             */
/*   Updated: 2024/07/19 15:50:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

static bool	pain_elem_get_killed(t_game *game, t_entity *entity)
{
	if (game == NULL || entity == NULL || game->entities == NULL)
		return (false);
	if (game->last_entity_updated->content == entity)
		game->last_entity_updated = game->last_entity_updated->next;
	entity->sprite->animation = game->textures[IDX_TXTR_PAIN_ELEM_DEATH];
	entity->sprite->next_animation = NULL;
	entity->sprite->animate = true;
	ft_lst_remove_if(&game->entities, entity, equal, t_entity_destroy);
	return (true);
}

static bool	pain_elem_get_damage(t_game *game, t_entity *entity, size_t damage)
{
	entity->sprite->next_animation = game->textures[IDX_TXTR_PAIN_ELEM_WALK];
	entity->sprite->animation = game->textures[IDX_TXTR_PAIN_ELEM_PAIN];
	entity->sprite->frame_update_delta = 0;
	damage_entity(game, entity, damage);
	return (true);
}

static bool	pain_elem_get_chainsawed(t_game *game, t_entity *entity)
{
	(void)game;
	(void)entity;
	return (true);
}

bool	pain_elem_init(t_entity *entity, t_list *textures[MAP_NB_IDS])
{
	entity->update = pain_elem_update;
	entity->get_killed = pain_elem_get_killed;
	entity->get_damage = pain_elem_get_damage;
	entity->get_chainsawed = pain_elem_get_chainsawed;
	entity->health_point = 0;
	entity->speed = PAIN_ELEM_SPEED;
	entity->squared_radius = PAIN_ELEM_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, textures[IDX_TXTR_PAIN_ELEM_WALK], WIN_HEIGHT);
	return (true);
}
