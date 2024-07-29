/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch_vile_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:49:15 by root              #+#    #+#             */
/*   Updated: 2024/07/23 21:15:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"
#include "bullets_bonus.h"

static bool	arch_vile_spawn(t_entity *entity, t_sprite *sprite, t_game *game)
{
	t_vector	position;
	t_vector	direction;
	t_entity	*new_lost_soul;

	if (entity->cooldown > 0)
		return (true);
	entity->cooldown = ARCH_VILE_SPAWN_PAUSE;
	get_entity_direction(&direction, &game->player.position, &sprite->position);
	if (!get_spawn_position(&position, entity, &direction, game))
		return (true);
	new_lost_soul = add_entity(game, 0, 0, ID_MAP_LOST_SOUL);
	if (!new_lost_soul)
		return (false);
	new_lost_soul->sprite->position.x = position.x;
	new_lost_soul->sprite->position.y = position.y;
	set_animation(entity->sprite, &game->anim[IDX_TXTR_ARCH_VILE_ATTACK]);
	sprite->next_animation = &game->anim[IDX_TXTR_ARCH_VILE_WALK];
	return (true);
}

bool	arch_vile_update(t_game *game, t_entity *entity, float delta_time)
{
	t_sprite	*sprite;

	if (entity->cooldown > 0)
		entity->cooldown -= delta_time;
	sprite = entity->sprite;
	sprite->animate = true;
	if (!entity->see_player)
		update_entity_position(entity, delta_time, game->entities, &game->map);
	else
	{
		stop_walk_animation(entity);
		return (arch_vile_spawn(entity, sprite, game));
	}
	return (true);
}

void	arch_vile_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = arch_vile_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_ARCH_VILE_WALK];
	entity->pain = &animation[IDX_TXTR_ARCH_VILE_PAIN];
	entity->death = &animation[IDX_TXTR_ARCH_VILE_DEATH];
	entity->close_attack = NULL;
	entity->range_attack = NULL;
	entity->health_point = ARCH_VILE_HEALTH_POINT;
	entity->speed = ARCH_VILE_SPEED;
	entity->squared_radius = ARCH_VILE_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_ARCH_VILE_WALK],
		WIN_HEIGHT);
	entity->sprite->on_ground = true;
	entity->sprite->height = WIN_HEIGHT * ARCH_VILE_HEIGHT_RATIO;
}
