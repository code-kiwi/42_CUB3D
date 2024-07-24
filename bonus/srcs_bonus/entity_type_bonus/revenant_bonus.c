/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revenant_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:50:44 by root              #+#    #+#             */
/*   Updated: 2024/07/23 21:15:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "entities_bonus.h"
#include "bullets_bonus.h"

bool	revenant_update(t_game *game, t_entity *entity, float delta_time)
{
	float		distance;
	t_sprite	*sprite;

	if (entity->cooldown > 0)
		entity->cooldown -= delta_time;
	sprite = entity->sprite;
	distance = get_distance(&sprite->position, &game->player.position);
	sprite->animate = true;
	if (distance < REV_CLOSE_ATTACK_RANGE)
	{
		stop_walk_animation(entity);
		close_attack(entity, game, REV_CLOSE_PAUSE, REV_CLOSE_DAMAGE);
	}
	else if (!entity->see_player)
	{
		update_entity_position(entity, delta_time, game->entities, &game->map);
		if (entity->path == NULL)
			stop_walk_animation(entity);
	}
	else
	{
		stop_walk_animation(entity);
		return (range_attack(entity, game, REV_RANGE_PAUSE, rev_proj_init));
	}
	return (true);
}

bool	revenant_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = revenant_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_REV_WALK];
	entity->pain = &animation[IDX_TXTR_REV_PAIN];
	entity->death = &animation[IDX_TXTR_REV_DEATH];
	entity->close_attack = &animation[IDX_TXTR_REV_PUNCH];
	entity->range_attack = &animation[IDX_TXTR_REV_SHOOT];
	entity->health_point = REV_HEALTH_POINT;
	entity->speed = REV_SPEED;
	entity->squared_radius = REV_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_REV_WALK], WIN_HEIGHT);
	return (true);
}
