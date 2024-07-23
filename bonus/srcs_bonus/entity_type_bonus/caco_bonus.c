/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caco_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:59 by brappo            #+#    #+#             */
/*   Updated: 2024/07/19 15:50:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

bool	caco_init(t_entity *entity, t_animation anim[MAP_NB_IDS])
{
	entity->update = caco_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &anim[IDX_TXTR_CACO_WALK];
	entity->pain = &anim[IDX_TXTR_CACO_PAIN];
	entity->death = &anim[IDX_TXTR_CACO_DEATH];
	entity->health_point = CACO_HEALTH_POINT;
	entity->speed = CACO_SPEED;
	entity->squared_radius = CACO_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &anim[IDX_TXTR_CACO_WALK], WIN_HEIGHT);
	return (true);
}
