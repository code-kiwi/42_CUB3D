/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imp_update_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:50:44 by root              #+#    #+#             */
/*   Updated: 2024/07/19 15:52:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "entities_bonus.h"
#include "bullets_bonus.h"

bool	imp_update(t_game *game, t_entity *entity, float delta_time)
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
	if (distance < IMP_ATTACK_RANGE)
	{
		if (sprite->animation == game->textures[IDX_TXTR_IMP_WALK])
			sprite->animate = false;
		if (entity->cooldown > 0)
			return (true);
		sprite->next_animation = game->textures[IDX_TXTR_IMP_WALK];
		sprite->animation = game->textures[IDX_TXTR_IMP_ATTACK];
		entity->cooldown = IMP_ATTACK_PAUSE;
		player_get_damage(game, IMP_ATTACK_DAMAGE);
	}
	else
	{
		if (!entity->see_player)
			update_entity_position(entity, delta_time, game->entities, &game->map);
		else
		{
			if (entity->cooldown > 0)
				return (true);
			sprite->next_animation = game->textures[IDX_TXTR_IMP_WALK];
			sprite->animation = game->textures[IDX_TXTR_IMP_ATTACK];
			entity->cooldown = IMP_ATTACK_PAUSE;
			return (entity_shoot_bullet(game, entity, imp_projectile_use));
		}
	}
	return (true);
}