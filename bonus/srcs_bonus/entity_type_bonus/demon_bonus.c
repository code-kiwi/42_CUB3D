/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demon_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:59 by brappo            #+#    #+#             */
/*   Updated: 2024/07/23 12:11:36 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

static bool	demon_get_killed(t_game *game, t_entity *entity)
{
	if (game == NULL || entity == NULL || game->entities == NULL)
		return (false);
	if (game->last_entity_updated->content == entity)
		game->last_entity_updated = game->last_entity_updated->next;
	entity->sprite->animation = &game->anim[IDX_TXTR_DEMON_DEATH];
	entity->sprite->next_animation = NULL;
	entity->sprite->texture = entity->sprite->animation->textures;
	entity->sprite->animate = true;
	ft_lst_remove_if(&game->entities, entity, equal, t_entity_destroy);
	return (true);
}

static bool	demon_get_damage(t_game *game, t_entity *entity, size_t damage)
{
	entity->sprite->next_animation = &game->anim[IDX_TXTR_DEMON_WALK];
	entity->sprite->animation = &game->anim[IDX_TXTR_DEMON_PAIN];
	entity->sprite->frame_update_delta = 0;
	entity->sprite->texture = entity->sprite->animation->textures;
	damage_entity(game, entity, damage);
	return (true);
}

static bool	demon_get_chainsawed(t_game *game, t_entity *entity)
{
	(void)game;
	(void)entity;
	return (true);
}

bool	demon_init(t_entity *entity, t_animation anim[MAP_NB_IDS])
{
	entity->update = demon_update;
	entity->get_killed = demon_get_killed;
	entity->get_damage = demon_get_damage;
	entity->get_chainsawed = demon_get_chainsawed;
	entity->health_point = DEMON_HEALTH_POINT;
	entity->speed = DEMON_SPEED;
	entity->squared_radius = DEMON_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &anim[IDX_TXTR_DEMON_WALK], WIN_HEIGHT);
	return (true);
}
