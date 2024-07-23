/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyber_update_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:49:15 by root              #+#    #+#             */
/*   Updated: 2024/07/23 11:01:01 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"
#include "bullets_bonus.h"

static void	stop_walk_animation(t_sprite *sprite, t_animation animations[MAP_NB_IDS])
{
	if (sprite->animation == &animations[IDX_TXTR_CYBER_WALK])
		sprite->animate = false;
}

static void	cyber_close_attack(t_entity *entity, t_sprite *sprite, t_game *game)
{
	if (entity->cooldown > 0)
		return ;
	sprite->next_animation = &game->animations[IDX_TXTR_CYBER_WALK];
	sprite->animation = &game->animations[IDX_TXTR_CYBER_ATTACK];
	entity->cooldown = CYBER_CLOSE_ATTACK_PAUSE;
	player_get_damage(game, CYBER_CLOSE_ATTACK_DAMAGE);
}

static bool	cyber_range_attack(t_entity *entity, t_sprite *sprite, t_game *game)
{
	if (entity->cooldown > 0)
		return (true);
	sprite->next_animation = &game->animations[IDX_TXTR_CYBER_WALK];
	sprite->animation = &game->animations[IDX_TXTR_CYBER_ATTACK];
	entity->cooldown = CYBER_RANGE_ATTACK_PAUSE;
	return (entity_shoot_bullet(game, entity, rocket_projectile_init));
}

bool	cyber_update(t_game *game, t_entity *entity, float delta_time)
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
	if (distance < CYBER_CLOSE_ATTACK_RANGE)
	{
		stop_walk_animation(sprite, game->animations);
		cyber_close_attack(entity, sprite, game);
	}
	else
	{
		if (entity->see_player && !cyber_range_attack(entity, sprite, game))
			return (false);
		update_entity_position(entity, delta_time, game->entities, &game->map);
		if (entity->path == NULL)
			stop_walk_animation(sprite, game->animations);
	}
	return (true);
}
