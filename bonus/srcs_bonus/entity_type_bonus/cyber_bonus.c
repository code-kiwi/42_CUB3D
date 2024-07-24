/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyber_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:49:15 by root              #+#    #+#             */
/*   Updated: 2024/07/23 21:15:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"
#include "bullets_bonus.h"

bool	cyber_update(t_game *game, t_entity *entity, float delta_time)
{
	t_sprite	*sprite;

	if (entity->cooldown > 0)
		entity->cooldown -= delta_time;
	sprite = entity->sprite;
	sprite->animate = true;
	if (entity->see_player
		&& !range_attack(entity, game, CYBER_CLOSE_PAUSE, rocket_proj_init))
	{
		return (false);
	}
	update_entity_position(entity, delta_time, game->entities, &game->map);
	if (entity->path == NULL)
		stop_walk_animation(entity);
	return (true);
}

bool	cyber_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = cyber_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_CYBER_WALK];
	entity->pain = &animation[IDX_TXTR_CYBER_PAIN];
	entity->death = &animation[IDX_TXTR_CYBER_DEATH];
	entity->close_attack = NULL;
	entity->range_attack = &animation[IDX_TXTR_CYBER_ATTACK];
	entity->health_point = CYBER_HEALTH_POINT;
	entity->speed = CYBER_SPEED;
	entity->squared_radius = CYBER_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_CYBER_WALK], WIN_HEIGHT);
	return (true);
}
