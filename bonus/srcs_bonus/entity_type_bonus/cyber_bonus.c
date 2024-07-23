/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyber_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:59 by brappo            #+#    #+#             */
/*   Updated: 2024/07/23 13:19:46 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

static bool	cyber_get_killed(t_game *game, t_entity *entity)
{
	if (game == NULL || entity == NULL || game->entities == NULL)
		return (false);
	if (game->last_entity_updated->content == entity)
		game->last_entity_updated = game->last_entity_updated->next;
	set_animation(entity->sprite, &game->anim[IDX_TXTR_CYBER_DEATH]);
	entity->sprite->next_animation = NULL;
	ft_lst_remove_if(&game->entities, entity, equal, t_entity_destroy);
	return (true);
}

static bool	cyber_get_damage(t_game *game, t_entity *entity, size_t damage)
{
	set_animation(entity->sprite, &game->anim[IDX_TXTR_CYBER_PAIN]);
	entity->sprite->next_animation = &game->anim[IDX_TXTR_CYBER_WALK];
	damage_entity(game, entity, damage);
	return (true);
}

static bool	cyber_get_chainsawed(t_game *game, t_entity *entity)
{
	(void)game;
	(void)entity;
	return (true);
}

bool	cyber_init(t_entity *entity, t_animation anim[MAP_NB_IDS])
{
	entity->update = cyber_update;
	entity->get_killed = cyber_get_killed;
	entity->get_damage = cyber_get_damage;
	entity->get_chainsawed = cyber_get_chainsawed;
	entity->health_point = CYBER_HEALTH_POINT;
	entity->speed = CYBER_SPEED;
	entity->squared_radius = CYBER_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &anim[IDX_TXTR_CYBER_WALK], WIN_HEIGHT);
	return (true);
}
