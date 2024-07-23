/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demon_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:49:15 by root              #+#    #+#             */
/*   Updated: 2024/07/23 21:15:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

static void	demon_attack(t_entity *entity, t_sprite *sprite, t_game *game)
{
	if (entity->cooldown > 0)
		return ;
	set_animation(entity->sprite, &game->anim[IDX_TXTR_DEMON_ATTACK]);
	sprite->next_animation = &game->anim[IDX_TXTR_DEMON_WALK];
	entity->cooldown = DEMON_ATTACK_PAUSE;
	player_get_damage(game, DEMON_ATTACK_DAMAGE);
}

bool	demon_update(t_game *game, t_entity *entity, float delta_time)
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
	if (distance < DEMON_ATTACK_RANGE)
	{
		stop_walk_animation(entity);
		demon_attack(entity, sprite, game);
	}
	else
	{
		update_entity_position(entity, delta_time, game->entities, &game->map);
		if (entity->path == NULL)
			stop_walk_animation(entity);
	}
	return (true);
}

bool	demon_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = demon_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_DEMON_WALK];
	entity->pain = &animation[IDX_TXTR_DEMON_PAIN];
	entity->death = &animation[IDX_TXTR_DEMON_DEATH];
	entity->health_point = DEMON_HEALTH_POINT;
	entity->speed = DEMON_SPEED;
	entity->squared_radius = DEMON_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_DEMON_WALK], WIN_HEIGHT);
	return (true);
}

