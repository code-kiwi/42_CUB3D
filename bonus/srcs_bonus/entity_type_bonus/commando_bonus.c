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

static bool	commando_range_attack(t_entity *entity, t_sprite *sprite,
	t_game *game)
{
	if (entity->cooldown > 0)
		return (true);
	set_animation(entity->sprite, &game->anim[IDX_TXTR_COMMANDO_ATTACK]);
	sprite->next_animation = &game->anim[IDX_TXTR_COMMANDO_WALK];
	entity->cooldown = COMMANDO_ATTACK_PAUSE;
	return (entity_shoot_bullet(game, entity, imp_projectile_init));
}

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
		return (commando_range_attack(entity, sprite, game));
	}
	return (true);
}

bool	commando_init(t_entity *entity, t_animation anim[MAP_NB_IDS])
{
	entity->update = commando_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &anim[IDX_TXTR_COMMANDO_WALK];
	entity->pain = &anim[IDX_TXTR_COMMANDO_PAIN];
	entity->death = &anim[IDX_TXTR_COMMANDO_DEATH];
	entity->health_point = COMMANDO_HEALTH_POINT;
	entity->speed = COMMANDO_SPEED;
	entity->squared_radius = COMMANDO_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &anim[IDX_TXTR_COMMANDO_WALK], WIN_HEIGHT);
	return (true);
}
