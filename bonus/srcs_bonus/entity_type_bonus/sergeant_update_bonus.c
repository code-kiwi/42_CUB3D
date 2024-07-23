/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sergeant_update_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:50:44 by root              #+#    #+#             */
/*   Updated: 2024/07/23 20:59:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "entities_bonus.h"
#include "bullets_bonus.h"

static bool	sergeant_range_attack(t_entity *entity, t_sprite *sprite,
	t_game *game)
{
	if (entity->cooldown > 0)
		return (true);
	set_animation(sprite, &game->anim[IDX_TXTR_SERGEANT_ATTACK]);
	sprite->next_animation = &game->anim[IDX_TXTR_SERGEANT_WALK];
	entity->cooldown = SERGEANT_ATTACK_PAUSE;
	return (entity_shoot_bullet(game, entity, imp_projectile_init));
}

bool	sergeant_update(t_game *game, t_entity *entity, float delta_time)
{
	t_sprite	*sprite;

	if (entity->cooldown > 0)
		entity->cooldown -= delta_time;
	sprite = entity->sprite;
	sprite->animate = true;
	if (!entity->see_player)
	{
		update_entity_position(entity, delta_time, game->entities, &game->map);
		if (entity->path == NULL)
			stop_walk_animation(entity);
	}
	else
	{
		stop_walk_animation(entity);
		return (sergeant_range_attack(entity, sprite, game));
	}
	return (true);
}
