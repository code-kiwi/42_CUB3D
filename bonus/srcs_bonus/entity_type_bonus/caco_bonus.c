/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caco_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:59 by brappo            #+#    #+#             */
/*   Updated: 2024/07/19 15:50:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

static bool	caco_get_killed(t_game *game, t_entity *entity)
{
	if (game == NULL || entity == NULL || game->entities == NULL)
		return (false);
	if (game->last_entity_updated->content == entity)
		game->last_entity_updated = game->last_entity_updated->next;
	entity->sprite->animation = game->textures[IDX_TXTR_CACO_DEATH];
	entity->sprite->next_animation = NULL;
	entity->sprite->animate = true;
	ft_lst_remove_if(&game->entities, entity, equal, t_entity_destroy);
	return (true);
}

static bool	caco_get_damage(t_game *game, t_entity *entity, size_t damage)
{
	entity->sprite->next_animation = game->textures[IDX_TXTR_CACO_WALK];
	entity->sprite->animation = game->textures[IDX_TXTR_CACO_PAIN];
	entity->sprite->frame_update_delta = 0;
	damage_entity(game, entity, damage);
	return (true);
}

static bool	caco_get_chainsawed(t_game *game, t_entity *entity)
{
	(void)game;
	(void)entity;
	return (true);
}

bool	caco_init(t_entity *entity, t_list *textures[MAP_NB_IDS])
{
	entity->update = caco_update;
	entity->get_killed = caco_get_killed;
	entity->get_damage = caco_get_damage;
	entity->get_chainsawed = caco_get_chainsawed;
	entity->health_point = CACO_HEALTH_POINT;
	entity->speed = CACO_SPEED;
	entity->squared_radius = CACO_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, textures[IDX_TXTR_CACO_WALK], WIN_HEIGHT);
	return (true);
}
