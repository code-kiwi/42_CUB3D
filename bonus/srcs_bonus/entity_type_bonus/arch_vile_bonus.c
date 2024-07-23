/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch_vile_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:59 by brappo            #+#    #+#             */
/*   Updated: 2024/07/23 13:19:38 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

static bool	arch_vile_get_killed(t_game *game, t_entity *entity)
{
	if (game == NULL || entity == NULL || game->entities == NULL)
		return (false);
	if (game->last_entity_updated->content == entity)
		game->last_entity_updated = game->last_entity_updated->next;
	set_animation(entity->sprite, &game->anim[IDX_TXTR_ARCH_VILE_DEATH]);
	entity->sprite->next_animation = NULL;
	ft_lst_remove_if(&game->entities, entity, equal, t_entity_destroy);
	return (true);
}

static bool	arch_vile_get_damage(t_game *game, t_entity *entity, size_t damage)
{
	set_animation(entity->sprite, &game->anim[IDX_TXTR_ARCH_VILE_PAIN]);
	entity->sprite->next_animation = &game->anim[IDX_TXTR_ARCH_VILE_WALK];
	damage_entity(game, entity, damage);
	return (true);
}

static bool	arch_vile_get_chainsawed(t_game *game, t_entity *entity)
{
	(void)game;
	(void)entity;
	return (true);
}

bool	arch_vile_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = arch_vile_update;
	entity->get_killed = arch_vile_get_killed;
	entity->get_damage = arch_vile_get_damage;
	entity->get_chainsawed = arch_vile_get_chainsawed;
	entity->health_point = ARCH_VILE_HEALTH_POINT;
	entity->speed = ARCH_VILE_SPEED;
	entity->squared_radius = ARCH_VILE_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_ARCH_VILE_WALK],
		WIN_HEIGHT);
	return (true);
}
