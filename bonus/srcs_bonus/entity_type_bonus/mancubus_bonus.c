/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mancubus_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:50:44 by root              #+#    #+#             */
/*   Updated: 2024/07/23 21:17:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "entities_bonus.h"
#include "bullets_bonus.h"

static void	mancubus_close_attack(t_entity *entity, t_sprite *sprite,
	t_game *game)
{
	if (entity->cooldown > 0)
		return ;
	set_animation(entity->sprite, &game->anim[IDX_TXTR_MANCUBUS_ATTACK]);
	sprite->next_animation = &game->anim[IDX_TXTR_MANCUBUS_WALK];
	entity->cooldown = MANCUBUS_CLOSE_ATTACK_PAUSE;
	player_get_damage(game, MANCUBUS_CLOSE_ATTACK_DAMAGE);
}

static bool	mancubus_range_attack(t_entity *entity, t_sprite *sprite,
	t_game *game)
{
	if (entity->cooldown > 0)
		return (true);
	set_animation(entity->sprite, &game->anim[IDX_TXTR_MANCUBUS_ATTACK]);
	sprite->next_animation = &game->anim[IDX_TXTR_MANCUBUS_WALK];
	entity->cooldown = MANCUBUS_RANGE_ATTACK_PAUSE;
	return (entity_shoot_bullet(game, entity, mancubus_projectile_init));
}

bool	mancubus_update(t_game *game, t_entity *entity, float delta_time)
{
	float		distance;
	t_sprite	*sprite;

	if (entity->cooldown > 0)
		entity->cooldown -= delta_time;
	sprite = entity->sprite;
	distance = get_distance(&sprite->position, &game->player.position);
	sprite->animate = true;
	if (distance < MANCUBUS_CLOSE_ATTACK_RANGE)
	{
		stop_walk_animation(entity);
		mancubus_close_attack(entity, sprite, game);
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
		return (mancubus_range_attack(entity, sprite, game));
	}
	return (true);
}

bool	mancubus_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = mancubus_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_MANCUBUS_WALK];
	entity->pain = &animation[IDX_TXTR_MANCUBUS_PAIN];
	entity->death = &animation[IDX_TXTR_MANCUBUS_DEATH];
	entity->close_attack = &animation[IDX_TXTR_MANCUBUS_ATTACK];
	entity->range_attack = &animation[IDX_TXTR_MANCUBUS_ATTACK];
	entity->health_point = MANCUBUS_HEALTH_POINT;
	entity->speed = MANCUBUS_SPEED;
	entity->squared_radius = MANCUBUS_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_MANCUBUS_WALK], WIN_HEIGHT);
	return (true);
}
