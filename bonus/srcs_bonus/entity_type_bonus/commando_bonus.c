/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commando_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:50:44 by root              #+#    #+#             */
/*   Updated: 2024/07/23 21:15:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "entities_bonus.h"
#include "bullets_bonus.h"

bool	commando_update(t_game *game, t_entity *entity, float delta_time)
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
		return (entity_range_attack(entity, game, COMMANDO_ATTACK_PAUSE,
			imp_projectile_init));
	}
	return (true);
}

bool	commando_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = commando_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_COMMANDO_WALK];
	entity->pain = &animation[IDX_TXTR_COMMANDO_PAIN];
	entity->death = &animation[IDX_TXTR_COMMANDO_DEATH];
	entity->close_attack = NULL;
	entity->range_attack = &animation[IDX_TXTR_COMMANDO_ATTACK];
	entity->health_point = COMMANDO_HEALTH_POINT;
	entity->speed = COMMANDO_SPEED;
	entity->squared_radius = COMMANDO_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_COMMANDO_WALK], WIN_HEIGHT);
	return (true);
}
