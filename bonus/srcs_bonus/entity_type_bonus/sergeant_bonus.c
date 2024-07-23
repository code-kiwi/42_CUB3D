/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sergeant_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:59 by brappo            #+#    #+#             */
/*   Updated: 2024/07/23 20:04:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"
#include "bullets_bonus.h"

bool	sergeant_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = sergeant_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_SERGEANT_WALK];
	entity->pain = &animation[IDX_TXTR_SERGEANT_PAIN];
	entity->death = &animation[IDX_TXTR_SERGEANT_DEATH];
	entity->health_point = SERGEANT_HEALTH_POINT;
	entity->speed = SERGEANT_SPEED;
	entity->squared_radius = SERGEANT_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_SERGEANT_WALK], WIN_HEIGHT);
	return (true);
}
