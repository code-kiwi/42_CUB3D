/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revenant_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:59 by brappo            #+#    #+#             */
/*   Updated: 2024/07/23 13:19:59 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"
#include "bullets_bonus.h"

static bool	revenant_get_killed(t_game *game, t_entity *entity)
{
	if (game == NULL || entity == NULL || game->entities == NULL)
		return (false);
	if (game->last_entity_updated->content == entity)
		game->last_entity_updated = game->last_entity_updated->next;
	set_animation(entity->sprite, &game->anim[IDX_TXTR_REV_PROJ_DEATH]);
	entity->sprite->next_animation = NULL;
	ft_lst_remove_if(&game->entities, entity, equal, t_entity_destroy);
	return (true);
}

static bool	revenant_get_damage(t_game *game, t_entity *entity, size_t damage)
{
	set_animation(entity->sprite, &game->anim[IDX_TXTR_REVENANT_PAIN]);
	entity->sprite->next_animation = &game->anim[IDX_TXTR_REVENANT_WALK];
	damage_entity(game, entity, damage);
	return (true);
}

static bool	revenant_get_chainsawed(t_game *game, t_entity *entity)
{
	(void)game;
	(void)entity;
	return (true);
}

bool	revenant_init(t_entity *entity, t_animation anim[MAP_NB_IDS])
{
	entity->update = revenant_update;
	entity->get_killed = revenant_get_killed;
	entity->get_damage = revenant_get_damage;
	entity->get_chainsawed = revenant_get_chainsawed;
	entity->health_point = REVENANT_HEALTH_POINT;
	entity->speed = REVENANT_SPEED;
	entity->squared_radius = REVENANT_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &anim[IDX_TXTR_REVENANT_WALK], WIN_HEIGHT);
	return (true);
}
