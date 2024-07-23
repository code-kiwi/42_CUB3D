/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commando_update_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:50:44 by root              #+#    #+#             */
/*   Updated: 2024/07/23 19:25:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "entities_bonus.h"
#include "bullets_bonus.h"

static void	stop_walk_animation(t_sprite *sprite, t_animation anim[MAP_NB_IDS])
{
	if (sprite->animation == &anim[IDX_TXTR_COMMANDO_WALK])
		sprite->animate = false;
}

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
			stop_walk_animation(sprite, game->anim);
	}
	else
	{
		stop_walk_animation(sprite, game->anim);
		return (commando_range_attack(entity, sprite, game));
	}
	return (true);
}
