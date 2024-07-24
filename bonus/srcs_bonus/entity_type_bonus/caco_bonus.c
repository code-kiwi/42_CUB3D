/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caco_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:49:15 by root              #+#    #+#             */
/*   Updated: 2024/07/19 17:14:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"
#include "bullets_bonus.h"

bool	caco_update(t_game *game, t_entity *entity, float delta_time)
{
	t_player	*player;
	float		distance;
	t_sprite	*sprite;

	if (entity->cooldown > 0)
		entity->cooldown -= delta_time;
	sprite = entity->sprite;
	player = &game->player;
	distance = get_distance(&sprite->position, &player->position);
	sprite->animate = true;
	if (distance < CACO_CLOSE_ATTACK_RANGE)
	{
		entity_close_attack(entity, game, CACO_CLOSE_PAUSE,
			CACO_CLOSE_DAMAGE);
	}
	else
	{
		if (!entity_range_attack(entity, game, CACO_RANGE_PAUSE,
			caco_proj_init))
			return (false);
		update_entity_position(entity, delta_time, game->entities, &game->map);
	}
	return (true);
}

bool	caco_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = caco_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_CACO_WALK];
	entity->pain = &animation[IDX_TXTR_CACO_PAIN];
	entity->death = &animation[IDX_TXTR_CACO_DEATH];
	entity->close_attack = &animation[IDX_TXTR_CACO_ATTACK];
	entity->range_attack = &animation[IDX_TXTR_CACO_ATTACK];
	entity->health_point = CACO_HEALTH_POINT;
	entity->speed = CACO_SPEED;
	entity->squared_radius = CACO_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_CACO_WALK], WIN_HEIGHT);
	return (true);
}
