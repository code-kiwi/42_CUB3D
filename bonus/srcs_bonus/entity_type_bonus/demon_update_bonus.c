/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demon_update_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:49:15 by root              #+#    #+#             */
/*   Updated: 2024/07/19 15:51:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

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
		if (sprite->animation == game->textures[IDX_TXTR_DEMON_WALK])
			sprite->animate = false;
		if (entity->cooldown > 0)
			return (true);
		sprite->next_animation = game->textures[IDX_TXTR_DEMON_WALK];
		sprite->animation = game->textures[IDX_TXTR_DEMON_ATTACK];
		entity->cooldown = DEMON_ATTACK_PAUSE;
		player_get_damage(game, DEMON_ATTACK_DAMAGE);
	}
	else
		update_entity_position(entity, delta_time, game->entities, &game->map);
	return (true);
}